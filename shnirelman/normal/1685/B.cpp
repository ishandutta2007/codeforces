#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
const int N = 2e5 + 13;
const int LOGN = 20;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

int inv(int n) {
    return pow2(n, M - 2);
}

mt19937 rnd(0);

/*
*/

bool cmp(int a, int b) {
    if(a % 2 == b % 2)
        return (a > b);
    else
        return (a % 2 == 1);
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    string s;
    cin >> s;

    int n = s.size();

    vector<int> cnt(2, 0);
    for(int i = 0; i < n; i++) {
        cnt[s[i] - 'A']++;
    }

    if(cnt[0] != a + c + d || cnt[1] != b + c + d) {
        cout << "NO\n";
        return;
    }

//    set<int> st1, st2;
//    for(int i = 0; i < n - 1; i++) {
//        if(s[i] != s[i + 1]) {
//            if(s[i] == 'A')
//                st1.insert(i);
//            else
//                st2.insert(i);
//        }
//    }

    bool res = true;

    vector<int> x, y;
    for(int i = 0; i < n - 1; ) {
//        if(s[i] != s[i + 1]) {
            int j = i + 1;
            while(j < n && s[j] != s[j - 1]) {
                j++;
            }
            if(s[i] == 'A')
                x.push_back(j - i);
            else
                y.push_back(j - i);
            i = j;

//        }
    }

    sort(x.begin(), x.end(), cmp);
    sort(y.begin(), y.end(), cmp);

//    for(int z : x)
//        cout << z << ' ';
//    cout << endl;
//    for(int z : y)
//        cout << z << ' ';
//    cout << endl;


    while(!x.empty() && c > 0) {
        if(x.back() > c * 2) {
            x.back() -= c * 2;
            c = 0;
        } else {
            c -= x.back() / 2;
            x.pop_back();
        }
    }

    while(!y.empty() && d > 0) {
        if(y.back() > d * 2) {
            y.back() -= d * 2;
            d = 0;
        } else {
            d -= y.back() / 2;
            y.pop_back();
        }
    }

//    cout << "c = " << c << "   d = " << d << endl;
//
//    for(int z : x)
//        cout << z << ' ';
//    cout << endl;
//    for(int z : y)
//        cout << z << ' ';
//    cout << endl;


    if(c > 0) {
        while(!y.empty() && c > 0) {
            c -= (y.back() - 1) / 2;
            y.pop_back();
        }
    } else {
        while(!x.empty() && d > 0) {
            d -= (x.back() - 1) / 2;
            x.pop_back();
        }
    }

    res = (c <= 0 && d <= 0);

//    while(c > 0 || d > 0) {
//        int del = -1;
//        if(c == 0)
//            del = 1;
//        else if(d == 0)
//            del = 0;
//        else {
//
//        }
//
//        if(c > 0 && (c >= st1.size() || d == 0 || d - int(st2.count(*st1.begin() + 1)) - int(st2.count(*st1.begin() - 1)) <= st2.size())) {
//            if(st1.empty()) {
//                res = false;
//                break;
//            }
//
//            st2.erase(*st1.begin() + 1);
//            st2.erase(*st1.begin() - 1);
//            st1.erase(st1.begin());
//            c--;
//        } else {
//            if(st2.empty()) {
//                res = false;
//                break;
//            }
//
//            st1.erase(*st2.begin() + 1);
//            st1.erase(*st2.begin() - 1);
//            st2.erase(st2.begin());
//            d--;
//        }
//    }

    cout << (res ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}