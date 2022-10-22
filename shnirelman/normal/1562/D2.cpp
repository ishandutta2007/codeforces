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
3
14 1
+--++---++-++-
1 14
14 3
+--++---+++---
1 14
6 12
3 10
4 10
+-+-
1 1
1 2
1 3
1 4
2 2
2 3
2 4
3 3
3 4
4 4


1
14 1
+--++---+++---
1 14

*/

void solve() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> p(n + 1, 0);
    for(int i = 0; i < n; i++) {
        p[i + 1] = p[i] + (s[i] == '+' ? 1 : -1) * (i % 2 == 0 ? 1 : -1);
    }

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        a[i] = (s[i] == '+' ? 1 : -1) * (i % 2 == 0 ? 1 : -1);
    }

    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++) {
        mp[p[i] * 2 + a[i]].push_back(i);
    }

//    for(int i = 0; i < n; i++) {
//        cout << a[i] << ' ';
//    }
//    cout << endl;
//    for(int i = 0; i <= n; i++) {
//        cout << p[i] << ' ';
//    }
//    cout << endl;

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        l--;

        int sum = p[r] - p[l];

        if(sum == 0)
            cout << 0 << '\n';
        else {
            bool fl = false;
            if((r - l) % 2 == 0) {
                fl = true;
                r--;
            }

//            for(int j = l; j < r; j++) {
//                cout << j << " : " << p[j] - p[l] - a[j] - 2 * ()
//            }

//            cout << p[l] + p[r] << endl;
//            for(auto x : mp[p[l] + p[r]])
//                cout << x << endl;

            int j = *lower_bound(mp[p[l] + p[r]].begin(), mp[p[l] + p[r]].end(), l);// - mp[p[l] + 2 * p[r]].begin();

//            cout << "res " << p[j] - p[l] - p[r] + p[j + 1] << endl;
//            int rs = 0;
//            for(int k = l; k < j; k++)
//                rs += a[k];
//            for(int k = j + 1; k < r; k++)
//                rs -= a[k];
//            cout << "rs " << rs << endl;

            cout << 1 + fl << '\n';
            cout << j + 1;
            if(fl)
                cout << ' ' << r + 1;
            cout << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }



}