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
using pci = pair<char, li>;
//using matr

//const li INF = 2e18 + 13;
const int INF = 1e9 + 13;
const int N = 3e5 + 13;
const int M = 1e9 + 7;//998244353;
const int B = 350;
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

int d[N];
vector<int> p;

void solve() {
    int n;
    char c;
    cin >> n >> c;

    string s;
    cin >> s;

    vector<int> a;
    vector<bool> b(n + 1, false);
    for(int i = 0; i < n; i++) {
        if(s[i] != c) {
            a.push_back(i + 1);
            b[i + 1] = true;
        }

    }

    if(a.empty()) {
        cout << 0 << endl;
        return;
    }

    for(int i = 1; i <= n; i++) {
        bool res = true;
        for(int j = i; j <= n; j += i) {
            if(b[j])
                res = false;
        }

        if(res) {
            cout << 1 << endl << i << endl;
            return;
        }
    }

    cout << 2 << endl << n - 1 << ' ' << n << endl;
}

signed main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

//    for(int i = 2; i < N; i++) {
//        if(d[i] == 0) {
//            d[i] = i;
//            p.push_back(i);
//
//            if(i * 1ll * i < N)
//                for(int j = i * i; j < N; j += i)
//                    d[j] = i;
//        }
//    }

    int t;
    cin >> t;

    while(t--)
        solve();
}