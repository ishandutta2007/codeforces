#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1e5 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

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

    if(k % 2)
        return mul(pw, n);
    else
        return pw;
}
/*
*/

vector<int> dv;

void calc(vector<pii>& p, int i, int cur) {
    if(i == p.size()) {
        if(cur != 1)
            dv.push_back(cur);
        return;
    }

    for(int j = 0; j <= p[i].s; j++) {
        calc(p, i + 1, cur);
        cur *= p[i].f;
    }
}

void solve() {
    int n;
    cin >> n;

    vector<pii> p;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            p.emplace_back(i, 0);
            while(n % i == 0) {
                p.back().s++;
                n /= i;
            }
        }
    }

    if(n > 1) {
        p.emplace_back(n, 1);
    }

    if(p.size() == 2 && p[0].s == 1 && p[1].s == 1) {
        cout << p[0].f << ' ' << p[1].f << ' ' << p[0].f * p[1].f << endl;
        cout << 1 << endl;
        return;
    }

    dv.erase(dv.begin(), dv.end());
    calc(p, 0, 1);

    int lst = dv.size();
    for(int i = int(dv.size()) - 2; i >= 0; i--) {
        if(__gcd(dv[i], dv[i + 1]) == 1) {
            reverse(dv.begin() + i + 1, dv.begin() + lst);
            lst = i + 1;
        }
    }

    for(int i = int(dv.size()) - 1; i >= 0; i--) {
        if(__gcd(dv[0], dv[i]) != 1) {
            swap(dv[i], dv[dv.size() - 1]);
            break;
        }
    }

    for(auto x : dv)
        cout << x << ' ';
    cout << endl;
    cout << 0 << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}