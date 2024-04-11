#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using matr = vector<vi>;

const int INF = 1e9 + 13;


/*
4 5
0 1
1 2
2 3
3 4

1 6
4 4
*/

//vector<int> hungary(vector<vector<int>> a) {
//    int n = a.size();
//    int m = n;
//    vector<int> u(n), v(m), p(m), way(m);
//    for (int i = 1; i < n; i++) {
//        p[0] = i;
//        int j0 = 0;
//        vector<int> minv(m, INF);
//        vector<char> used(m, false);
//        do {
//            used[j0] = true;
//            int i0 = p[j0],  delta = INF,  j1;
//            for (int j=1; j < m; ++j)
//                if (!used[j]) {
//                    int cur = a[i0][j]-u[i0]-v[j];
//                    if (cur < minv[j])
//                        minv[j] = cur,  way[j] = j0;
//                    if (minv[j] < delta)
//                        delta = minv[j],  j1 = j;
//                }
//            for (int j=0; j < m; ++j)
//                if (used[j])
//                    u[p[j]] += delta,  v[j] -= delta;
//                else
//                    minv[j] -= delta;
//            j0 = j1;
//        } while (p[j0] != 0);
//        do {
//            int j1 = way[j0];
//            p[j0] = p[j1];
//            j0 = j1;
//        } while (j0);
//    }
//
//    vector<int> ans(n);
//    for (int j = 1; j < m; ++j)
//        ans[p[j]] = j;
//
//    return ans;
//}


vector<int> hungary(vector<vector<int>> a) {
    int n = a.size() - 1;
    int m = n;
    vector<int> u (n+1), v (m+1), p (m+1), way (m+1);
    for (int i=1; i<=n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<int> minv (m+1, INF);
        vector<char> used (m+1, false);
        do {
            used[j0] = true;
            int i0 = p[j0],  delta = INF,  j1;
            for (int j=1; j<=m; ++j)
                if (!used[j]) {
                    int cur = a[i0][j]-u[i0]-v[j];
                    if (cur < minv[j])
                        minv[j] = cur,  way[j] = j0;
                    if (minv[j] < delta)
                        delta = minv[j],  j1 = j;
                }
            for (int j=0; j<=m; ++j)
                if (used[j])
                    u[p[j]] += delta,  v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }

//    cout << "cost " << -v[0] << endl;

    vector<int> ans (n+1);
    for (int j=1; j<=m; ++j)
        ans[j] = p[j];
//        ans[p[j]] = j;

//    for(auto x : ans)
//        cout << x << ' ';
//    cout << endl;
    return ans;
}

/*
1
5 2
5 3
7 0
5 0
4 0
10 0

1
2 1
10 100
50 10

1
5 5
1 5
2 4
3 3
4 2
5 1

1
3 2
5 3
7 0
0 0


*/


void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k - 1; j++) {
            a[i + 1][j + 1] = x[i] + y[i] * j;
        }

        for(int j = k - 1; j < n - 1; j++) {
            a[i + 1][j + 1] = y[i] * (k - 1);
        }

        a[i + 1][n] = x[i] + y[i] * (k - 1);
    }



    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++)
            a[i][j] = -a[i][j];
    }

//    for(int i = 0; i <= n; i++) {
//        for(int j = 0; j <= n; j++) {
//            cout << a[i][j] << ' ';
//        }
//        cout << endl;
//    }
//    cout << endl;


    vector<int> res = hungary(a);

    vector<int> ans;
    for(int i = 0; i < k - 1; i++) {
        ans.push_back(res[i + 1]);
    }

    for(int i = k - 1; i < n - 1; i++) {
        ans.push_back(res[i + 1]);
        ans.push_back(-res[i + 1]);
    }

    ans.push_back(res[n]);

    cout << ans.size() << endl;
    for(auto x : ans)
        cout << x << ' ';
    cout << endl;
}

int main() {


    int t = 1;
    cin >> t;

    while(t--)
        solve();
}