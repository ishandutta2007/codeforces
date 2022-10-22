#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n, m;
    cin >> n >> m;
    vector <vector <bool> > can(m, vector <bool> (m, true));
    vector <int> masks(m, 0);
    map <string, int> num;
    int last = 0;
    vector <int> now(m, 0);
    for (int i = 0; i < n; i++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            now.clear();
            now.resize(m, 0);
        } else {
            string s;
            cin >> s;
            if (!num.count(s)) {
                num[s] = last++;
            }
            now[num[s]]++;
            for (int j = 0; j < m; j++) {
                if (j == num[s]) continue;
                if (now[j]) {
                    can[num[s]][j] = false;
                    can[j][num[s]] = false;
                }
            }
        }
    }
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < m; j++) {
//            cout << can[i][j] << " ";
//        }
//        cout << "\n";
//    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m / 2; j++) {
            if (!can[i][j]) {
                masks[i] |= (1 << j);
            }
        }
    }
    const int N = 1 << m / 2;
    vector <int> gmask(N, 0);
    for (int mask = 1; mask < N; mask++) {
        bool cat = true;
        for (int i = 0; i < m / 2; i++) {
            if (!(mask & (1 << i))) continue;
            for (int j = 0; j < m / 2; j++) {
                if (!(mask & (1 << j))) continue;
                if (!can[i][j]) {
                    cat = false;
                    break;
                }
            }
            if (gmask[mask ^ (1 << i)] != __builtin_popcount(mask) - 1) {
                cat = false;
            }
            break;
        }
        if (cat) {
            gmask[mask] = __builtin_popcount(mask);
        } else {
            for (int i = 0; i < m / 2; i++) {
                 if (!(mask & (1 << i))) continue;
                 gmask[mask] = max(gmask[mask], gmask[mask ^ (1 << i)]);
            }
        }
    }
    const int M = 1 << (m - m / 2);
    vector <int> dmask(M, 0);
    int res = 0;
    for (int mask = 0; mask < M; mask++) {
        bool cat = true;
        for (int i = 0; i < m - m / 2; i++) {
            if (!(mask & (1 << i))) continue;
            for (int j = 0; j < m - m / 2; j++) {
                if (!(mask & (1 << j))) continue;
                if (!can[i + m / 2][j + m / 2]) {
                    cat = false;
                    break;
                }
            }
            if (dmask[mask ^ (1 << i)] != __builtin_popcount(mask) - 1) {
                cat = false;
            }
            break;
        }
        if (!cat) continue;
        dmask[mask] = __builtin_popcount(mask);
        int per = 0;
        for (int i = 0; i < m - m / 2; i++) {
             if (!(mask & (1 << i))) continue;
             per |= masks[i + m / 2];
        }
        //cout << mask << " " << (int) (per ^ (N - 1)) << " " << gmask[per ^ (N - 1)] << "\n";
        res = max(res, gmask[per ^ (N - 1)] + dmask[mask]);
    }
    cout << res;
}