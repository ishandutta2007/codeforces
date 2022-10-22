//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vint = vector<int>;
using matr = vector<vint>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 50 + 13;
const int M = 1e9 + 9;
const ld eps = 1e-6;
const int K = 103;
const int LOGN = 22;
const int A = 52;


/*
*/

int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, 1};

int p[N * N], sz[N * N];
bool ocean[N * N];

int getp(int x) {
    return (x == p[x] ? x : p[x] = getp(p[x]));
}

void unite(int x, int y) {
    x = getp(x);
    y = getp(y);

    if(x == y)
        return;

    if(sz[x] < sz[y])
        swap(x, y);

    p[y] = x;
    sz[x] += sz[y];
    ocean[x] |= ocean[y];
}

int n, m, k;

int get(int i, int j) {
    return i * m + j;
}

bool isin(int i, int j) {
    return (0 <= i && i < n && 0 <= j && j < m);
}

int a[N][N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m >> k;

    for(int i = 0; i < n * m; i++) {
        p[i] = i;
        sz[i] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;

            a[i][j] = (c == '.');
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 1) {
                for(int k = 0; k < 4; k++) {
                    int i1 = i + di[k];
                    int j1 = j + dj[k];

                    if(!isin(i1, j1)) {
                        ocean[getp(get(i, j))] = true;
                    }

                    if(!isin(i1, j1) || a[i1][j1] == 0)
                        continue;

//                    cout << "unite " << i << ' ' << j << ' ' << i1 << ' ' << j1 << endl;

                    unite(get(i, j), get(i1, j1));
                }
            }
        }
    }

    vector<pii> ord;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) if(a[i][j] == 1) {
            int ind = get(i, j);

            if(p[ind] == ind && !ocean[ind]) {
                ord.emplace_back(sz[ind], ind);
            }
        }
    }

    sort(ord.begin(), ord.end());

//    cout << ord.size() << endl;
//
//    for(int i = 0; i < n; i++) {
//        cout << "i " << i << endl;
//        for(int j = 0; j < m; j++) {
//            cout << get(i, j) << ' ' << getp(get(i, j)) << endl;
//        }
//        cout << endl;
//    }

    int ans = 0;
    for(int x = 0; x + k < ord.size(); x++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] == 1 && getp(get(i, j)) == ord[x].s) {
                    a[i][j] = 0;
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << (a[i][j] ? '.' : '*');
        }
        cout << endl;
    }
}