#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e4 + 13;
//const int M = 1e5 + 13;
const int A = 26;


signed main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n, 0));
    int cur = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= cur / 2; j++) {
            a[i][n / 2 + j] = a[i][n / 2 - j] = 1;
        }

        if(i >= n / 2)
            cur -= 2;
        else
            cur += 2;
    }

    int cur0 = 0, cur1 = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << (a[i][j] == 0 ? (cur0 += 2) : (cur1 += 2)) << ' ';
        }

        cout << endl;
    }

}