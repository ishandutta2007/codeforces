#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 1e9 + 7;
//const int M = 998244353;
const int N = 100 + 13;
const int LOGN = 30;

/*
*/

bool check(int n, int m, vector<vector<int>> a) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m - 1; j++) {
            if(a[i][j] > a[i][j + 1])
                return false;
        }
    }

    return true;
}

bool check(int n, int m, vector<vector<int>> a, int j1, int j2) {
    if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return false;

    for(int i = 0; i < n; i++) {
        swap(a[i][j1], a[i][j2]);
    }

    return check(n, m, a);
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int i1 = -1, j1 = -1;
    for(int i = 0; i < n && i1 == -1; i++) {
        for(int j = 0; j < m - 1; j++) {
//            cout << i << ' ' << j << endl;
            if(a[i][j] > a[i][j + 1]) {
                i1 = i;
                j1 = j;
                break;
            }
        }
    }

    if(i1 == -1) {
        cout << "1 1" << endl;
        return;
    }

    int j2 = -1, j3 = -1, j4 = -1;
    for(int j = 0; j < m; j++) {
        if(a[i1][j] == a[i1][j1] && j2 == -1)
            j2 = j;
        if(a[i1][j] == a[i1][j1 + 1])
            j3 = j;

        if(j < m - 1 && a[i1][j] > a[i1][j + 1])
            j4 = j;
    }

//    cout << i1 << ' ' << j1 << ' ' << j2 << ' ' << j3 << endl;

    if(check(n, m, a, j1 + 1, j2))
        cout << j1 + 2 << ' ' << j2 + 1 << endl;
    else if(check(n, m, a, j1, j3))
        cout << j1 + 1 << ' ' << j3 + 1 << endl;
    else if(j3 < m - 1 && check(n, m, a, j1, j3 + 1))
        cout << j1 + 1 << ' ' << j3 + 2 << endl;
    else if(j4 != -1 && check(n, m, a, j1, j4 + 1))
        cout << j1 + 1 << ' ' << j4 + 2 << endl;
    else if(j4 != -1 && check(n, m, a, j1 + 1, j4))
        cout << j1 + 2 << ' ' << j4 + 1 << endl;
    else
        cout << -1 << endl;

//    {
//        vector<vector<int>> b = a;
//        for(int i = 0; i < n; i++) {
//            swap(b[i][j1 + 1], b[i][j2]);
//        }
//
//        if(check(n, m, b)) {
//            cout << j1 + 2 << ' ' << j2 + 1 << endl;
//            return;
//        }
//    }
//
//    {
//        vector<vector<int>> b = a;
//        for(int i = 0; i < n; i++) {
//            swap(b[i][j1], b[i][j3]);
//        }
//
//        if(check(n, m, b)) {
//            cout << j1 + 1 << ' ' << j3 + 1 << endl;
//            return;
//        }
//    }


}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}