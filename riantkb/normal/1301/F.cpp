#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int M = 1000000007;


int dd[] = { 0, 1, 0, -1 };

inline bool inside(int i, int j, int h, int w) {
    return i >= 0 && i < h && j >= 0 && j < w;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w, col;
    cin >> h >> w >> col;

    vector<vector<int>> s(h, vector<int>(w)), lis(col), dist(col);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> s[i][j];
            --s[i][j];
            lis[s[i][j]].push_back(i * w + j);
        }
    }
    for (int i = 0; i < col; ++i) {
        vector<int> dis(h * w, M);
        vector<bool> used(col, false);
        used[i] = true;
        queue<int> q;
        for (auto& j : lis[i]) {
            dis[j] = 1;
            q.push(j);
        }
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            int pi = p / w, pj = p % w;
            if (!used[s[pi][pj]]) {
                for (auto& j : lis[s[pi][pj]]) {
                    if (dis[j] > dis[p] + 1) {
                        dis[j] = dis[p] + 1;
                        q.push(j);
                    }
                }
                used[s[pi][pj]] = true;
            }
            for (int k = 0; k < 4; ++k) {
                int ti = pi + dd[k], tj = pj + dd[k ^ 1];
                if (inside(ti, tj, h, w) && dis[ti * w + tj] > dis[p] + 1) {
                    dis[ti * w + tj] = dis[p] + 1;
                    q.push(ti * w + tj);
                }
            }
        }
        dist[i] = dis;
    }

    {
        int q;
        cin >> q;
        for (int i = 0; i < q; ++i) {
            int si, sj, gi, gj;
            cin >> si >> sj >> gi >> gj;
            --si;
            --sj;
            --gi;
            --gj;
            int ans = abs(si - gi) + abs(sj - gj);
            for (int j = 0; j < col; ++j) {
                ans = min(ans, dist[j][si * w + sj] + dist[j][gi * w + gj] - 1);
            }
            cout << ans << '\n';
        }
    }


    return 0;
}