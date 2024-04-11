//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;
//using matr

//const li INF = 2e18 + 13;
const int INF = 1e9 + 13;
const int N = 1e5 + 13;
const int M = 998244353;
const int B = 300;
//const int A = 26;
//const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

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

/*
*/

bool isp[N];

//bool isp(int x) {
//    if(x == 1)
//        return false;
//    for(int i = 2; i * 1ll * i <= x; i++)
//        if(x % i == 0)
//            return false;
//    return true;
//}

void solve() {
    int k;
    cin >> k;

    string s;
    cin >> s;

    vector<int> a(k);
    for(int i = 0; i < k; i++) {
        a[i] = s[i] - '0';
        if(!isp[a[i]]) {
//            cout << "ans : ";
            cout << 1 << endl << a[i] << endl;
            return;
        }
    }

    for(int i = 0; i < k; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i] == a[j]) {
                cout << 2 << endl << a[i] << a[i] << endl;
                return;
            }
        }
    }

    int ans = INF;
    for(int mask = 1; mask < (1 << k); mask++) {
        int cur = 1;
        int res = 0;
        for(int i = 0; i < k; i++) {
            if(mask & (1 << i)) {
                res = res * 10 + a[i];
            }
        }

        if(!isp[res])
            ans = min(ans, res);
    }

    int cnt = 0;
    int x = ans;
    while(x > 0) {
        cnt++;
        x /= 10;
    }
//cout << "ans : ";
    cout << cnt << endl << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 2; i < N; i++) {
        isp[i] = true;
    }

    for(int i = 2; i < N; i++) {
        if(isp[i]) {
            if(i * 1ll * i < N)
                for(int j = i * i; j < N; j += i)
                    isp[j] = false;
        }
    }

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }



}