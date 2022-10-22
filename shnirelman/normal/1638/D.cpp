#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1000 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
//const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

int n, m;

bool isin(int i, int j) {
    return (0 <= i && i < n && 0 <= j && j < m);
}

int a[N][N];
bool used[N][N];

int di[4][4] = {{-1, -1, 0, 0}, {-1, -1, 0, 0}, {0, 0, 1, 1}, {0, 0, 1, 1}};
int dj[4][4] = {{-1, 0, -1, 0}, {0, 1, 0, 1}, {-1, 0, -1, 0}, {0, 1, 0, 1}};

int can(int i, int j) {
    for(int k = 0; k < 4; k++) {
        bool fl = false;
        for(int d = 0; d < 4; d++) {
            int i1 = i + di[k][d];
            int j1 = j + dj[k][d];

            if(!isin(i1, j1) || !used[i1][j1] && a[i1][j1] != a[i][j]) {
                fl = true;
                break;
            }
        }

        if(!fl)
            return k;
    }

    return -1;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    queue<pair<pii, int>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int res = can(i, j);
            if(res != -1) {
                q.emplace(pii(i, j), res);
                used[i][j] = true;
            }
        }
    }

    vector<pair<pii, int>> ans;

    while(!q.empty()) {
        int i = q.front().f.f, j = q.front().f.s, k1 = q.front().s;
        if(k1 == 0)
            q.front().f.f--, q.front().f.s--;
        else if(k1 == 1)
            q.front().f.f--;
        else if(k1 == 2)
            q.front().f.s--;
        ans.emplace_back(q.front().f, a[i][j]);


        q.pop();

//        int x = a[i][j];
//        for(int d = 0; d < 4; d++) {
//            int i1 = i + di[k1][d], j1 = j + dj[k1][d];
//            if(a[i1][j1] == x) {
//                a[i1][j1] = -1;
//            }
//        }

        for(int i1 = max(0, i - 1); i1 <= min(n - 1, i + 1); i1++) {
            for(int j1 = max(0, j - 1); j1 <= min(m - 1, j + 1); j1++) {
                if(!used[i1][j1]) {
                    int res = can(i1, j1);
                    if(res != -1) {
                        q.emplace(pii(i1, j1), res);
                        used[i1][j1] = true;
                    }
                }
            }
        }
    }

    if(ans.size() < n * m) {
        cout << -1 << endl;
    } else {
        reverse(ans.begin(), ans.end());
        cout << n * m << endl;
        for(auto p : ans) {
            cout << p.f.f + 1 << ' ' << p.f.s + 1 << ' ' << p.s << '\n';
        }
    }
}