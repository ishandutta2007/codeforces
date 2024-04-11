#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1024;
const int MAXG = 1e6 + 100;

const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int N, M;
bool found[MAXN][MAXN];
int color[MAXN][MAXN];
int final[MAXN][MAXN];

vector<pair<int, int>> elt[MAXG];

int group = 1;
int get_unique() { return group++; }

int do_it(int i, int j) {
    found[i][j] = true;

    vector<pair<int, int>> ch;
    vector<int> fam;

    for (int d = 0; d < 4; d++) {
        int ni = i + dir[d][0];
        int nj = j + dir[d][1];

        if (ni < 0 || nj < 0) continue;
        if (ni == N || nj == M) continue;

        if (found[ni][nj]) continue;

        ch.emplace_back(ni, nj);
        fam.push_back(do_it(ni, nj));
    }

    int uniq = get_unique();

    if (!ch.size()) {
        color[i][j] = uniq;
        return 1;
    }

    bool leaf = false;
    for (int v : fam) leaf |= (v == 1);
    
    if (leaf) {
        int fs = 1;
        color[i][j] = uniq;

        for (int c = 0; c < ch.size(); c++) {
            if (fam[c] == 1) {
                color[ch[c].first][ch[c].second] = uniq;
                fs++;
            }
        }

        return fs;
    }

    for (int c = 0; c < ch.size(); c++) {
        if (fam[c] < 5) { 
            color[i][j] = color[ch[c].first][ch[c].second];
            return fam[c] + 1;
        }
    }

    auto p = ch.front();

    color[i][j] = uniq;
    color[p.first][p.second] = uniq;

    return 2;
}

void assign(int g) {
    vector<bool> ban(12, false);

    for (auto p : elt[g]) {
        for (int d = 0; d < 4; d++) {
            int i = p.first + dir[d][0];
            int j = p.second + dir[d][1];

            if (i < 0 || j < 0) continue;
            if (i >= N || j >= M) continue;

            if (final[i][j] == -1) continue;
            ban[final[i][j]] = true;
        }
    }

    if (g != 0) ban[0] = true;

    int r = 0;
    while (ban[r]) r++;

    for (auto p : elt[g])
        final[p.first][p.second] = r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    memset(color, 0xff, sizeof(color));

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;

            if (c == '#') {
                found[i][j] = true;
                color[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (found[i][j]) continue;
            int fs = do_it(i, j);

            if (fs == 1) {
                cout << -1 << "\n";
                return 0;
            }
        } 
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            elt[color[i][j]].emplace_back(i, j);            
        }
    }

    memset(final, -1, sizeof(final));
    for (int g = 0; g < group; g++) {
        assign(g);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            assert(final[i][j] >= 0);
            if (final[i][j] == 0) cout << '#';
            else cout << char('0' + final[i][j] - 1);
        }
        cout << "\n";
    }
}