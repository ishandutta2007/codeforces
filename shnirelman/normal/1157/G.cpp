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

const li INF = 2e18 + 13;
const int N = 200 + 13;
const int M = 998244353;
const int B = 300;
//const int A = 26;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

/*
*/

int a[N][N];
int b[N][N];
int s[N];

void check(int n, int m, vector<int> c) {
//    cout << "check" << endl;
//    for(auto x : c)
//        cout << x << ' ';
//    cout << endl;

    for(int i = 0; i < n; i++) {
        s[i] = 0;
        for(int j = 0; j < m; j++) {
            b[i][j] = a[i][j] ^ c[j];
            s[i] += b[i][j];
        }
    }



    vector<int> r(n, 0);

    bool fl = false;
    for(int i = 0; i < n; i++) {
        if(s[i] == 0 || s[i] == m) {
            if(fl)
                r[i] = (s[i] == 0);
            else
                r[i] = (s[i] == n);
        } else {
            if(fl)
                return;
            fl = true;
            if(b[i][0] == 1)
                r[i] = 1;
        }
    }

//    for(int i = n - 1; i >= 0; i--) {
//        if(s[i] == 0) {
//            r[i] = 1;
//        } else if(s[i] != m) {
//            if(b[i][0] == 1)
//                r[i] = 1;
//            break;
//        }
//    }
//
//    for(int i = 0; i < n; i++) {
//        if(s[i] == m) {
//            r[i] = 1;
//        } else if(s[i] != 0) {
//            if(b[i][0] == 1)
//                r[i] = 1;
//            break;
//        }
//    }

    int lst = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            b[i][j] ^= r[i];
            if(b[i][j] < lst)
                return;
            lst = b[i][j];
        }
    }

//        cout << "bbbbbbbb" << endl;
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < m; j++) {
//            cout << b[i][j] << ' ';
//        }
//        cout << endl;
//    }

    cout << "YES" << endl;
    for(auto x : r)
        cout << x;
    cout << endl;
    for(auto x : c)
        cout << x;
    cout << endl;
    exit(0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> c(m, 0);
    for(int i = 0; i < m; i++)
        c[i] = a[0][i];

    check(n, m, c);

    for(int i = 0; i < m; i++)
        c[i] = a[n - 1][i];

    check(n, m, c);

    cout << "NO" << endl;
}