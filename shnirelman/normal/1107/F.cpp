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


//vector<int>
li hungary(vector<vector<li>> a) {
    int n = a.size() - 1;
    int m = a[0].size() - 1;
    vector<li> u (n+1), v (m+1), p (m+1), way (m+1);
    for (int i=1; i<=n; ++i) {
        p[0] = i;
        li j0 = 0;
        vector<li> minv (m+1, INF);
        vector<char> used (m+1, false);
        do {
            used[j0] = true;
            li i0 = p[j0],  delta = INF,  j1;
            for (int j=1; j<=m; ++j)
                if (!used[j]) {
                    li cur = a[i0][j]-u[i0]-v[j];
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
            li j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }

//    cout << "cost " << -v[0] << endl;
    return v[0];

    vector<int> ans (n+1);
    for (int j=1; j<=m; ++j)
        ans[j] = p[j];
//        ans[p[j]] = j;

//    for(auto x : ans)
//        cout << x << ' ';
//    cout << endl;
//    return ans;
}

/*

*/



int main() {
    int n;
    cin >> n;

    vector<int> x(n), y(n), k(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> k[i];
    }

    vector<vector<li>> a(n + 1, vector<li>(n * 2 + 1, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            a[i + 1][j + 1] = min(j, k[i]) * 1ll * y[i] - x[i];
        }

        for(int j = n + 1; j <= 2 * n; j++)
            a[i + 1][j] = 0;
    }

    cout << hungary(a);
}