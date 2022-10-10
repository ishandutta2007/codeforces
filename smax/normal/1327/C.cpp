#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

#define INF 1000000000

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, grid[200][200] = {};
bool visited[200][200], done[200] = {};

bool invalid(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

bool dfs(int x, int y, int c) {
    if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || (grid[x][y] > 0 && grid[x][y] != c))
        return false;
    if (grid[x][y] == -c)
        return true;

    visited[x][y] = true;
    bool ret = false;
    for (int i=0; i<4; i++)
        ret |= dfs(x + dx[i], y + dy[i], c);

    return ret;
}

pair<int, int> start[200], nd[200];
vector<int> fin;

int getDist(int x, int y, int co) {
    vector<vector<int>> pred(n, vector<int>(m));
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(x, y, 0));
    visited[x][y] = true;
    while (!q.empty()) {
        int r, c, dist;
        tie(r, c, dist) = q.front();
        q.pop();

        if (r == nd[co-1].first && c == nd[co-1].second) {
            while (r != x || c != y) {
                fin.push_back(pred[r][c]);
                int nr = r - dx[pred[r][c]];
                int nc = c - dy[pred[r][c]];
                r = nr, c = nc;
            }
            reverse(fin.begin(), fin.end());
            return dist;
        }

        for (int i=0; i<4; i++) {
            int nr = r + dx[i], nc = c + dy[i];
            if (!invalid(nr, nc) && !visited[nr][nc] && !(grid[nr][nc] > 0 && grid[nr][nc] != co)) {
                pred[nr][nc] = i;
                visited[nr][nc] = true;
                q.push(make_tuple(nr, nc, dist + 1));
            }
        }
    }
    return INF;
}

int getDist(int x, int y, int c, vector<int> &path) {
    if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || (grid[x][y] > 0 && grid[x][y] != c))
        return INF;
    if (c == 1)
        DEBUG(x, y, path.size())
    if (nd[c-1].first == x && nd[c-1].second == y) {
        if (fin.empty() || path.size() < fin.size()) {
            fin = path;
        }
        return 0;
    }

    visited[x][y] = true;
    int ret = INF;
    for (int i=0; i<4; i++) {
        path.push_back(i);
        ret = min(ret, getDist(x + dx[i], y + dy[i], c, path));
        path.pop_back();
    }

//    if (c == 1)
//        DEBUG(x, y, ret + 1)
    return ret + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int k;
    cin >> n >> m >> k;
    for (int i=0; i<k; i++) {
        int x, y;
        cin >> x >> y;
        grid[x-1][y-1] = i + 1;
        start[i] = {x-1, y-1};
    }
    for (int i=0; i<k; i++) {
        int x, y;
        cin >> x >> y;
        grid[x-1][y-1] = -(i + 1);
        nd[i] = {x-1, y-1};
    }

    // FUCK EM ALL INTO ONE CORNER, THEN SHOVE EM AROUND THE WORLD
    if (n + m > n * m) {
        //DEBUG("ASDF")
        if (n == 1) {
            cout << 2*(m-1) << "\n";
            for (int i=0; i<m-1; i++)
                cout << 'R';
            for (int i=0; i<m-1; i++)
                cout << 'L';
            cout << "\n";
            return 0;
        }
        if (m == 1) {
            cout << 2*(n-1) << "\n";
            for (int i=0; i<n-1; i++)
                cout << 'D';
            for (int i=0; i<n-1; i++)
                cout << 'U';
            cout << "\n";
            return 0;
        }
        cout << "-1\n";
        return 0;
    }
    cout << n + m + n * m << "\n";
    for (int i=0; i<n; i++) {
        cout << 'U';
    }
    for (int i=0; i<m; i++)
        cout << 'L';
    for (int i=0; i<n; i++) {
        for (int j=0; j<m-1; j++) {
            cout << (i % 2 == 0 ? 'R' : 'L');
        }
        cout << 'D';
    }
    cout << "\n";
    return 0;

//
//    for (int i=0; i<k; i++) {
//        memset(visited, false, sizeof(visited));
//        if (!dfs(start[i].first, start[i].second, i + 1)) {
//            cout << "-1\n";
//            return 0;
//        }
//    }
//
////    int toGoal = k;
//    for (int i=0; i<k; i++)
//        if (grid[start[i].first][start[i].second] == -(i + 1)) {
//            done[i] = true;
////            toGoal--;
//        }
//
//    vector<pair<int, int>> disti;
//    for (int i=0; i<k; i++) {
//        memset(visited, false, sizeof(visited));
//        disti.emplace_back(getDist(start[i].first, start[i].second, i + 1), i);
//        DEBUG(disti.back());
//    }
//
//    sort(disti.begin(), disti.end());
//
//    vector<char> seq;
//    int f = 0;
//    while (f < k) {
//        int chip = disti[f].second;
//        if (done[chip]) {
//            f++;
//            continue;
//        }
//        memset(visited, false, sizeof(visited));
//        getDist(start[chip].first, start[chip].second, chip + 1);
//
//        // 0 - up, 1 - right, 2 - down, 3 - left
//        for (int i=0; i<k; i++) {
//            pair<int, int> old = start[i];
//            for (int dir : fin) {
//                if (!invalid(start[i].first + dx[dir], start[i].second + dy[dir])) {
//                    start[i].first += dx[dir];
//                    start[i].second += dy[dir];
//                    if (start[i] == nd[i]) {
//                        done[i] = true;
//                    }
//                }
//            }
//            grid[old.first][old.second] = 0;
//            grid[start[i].first][start[i].second] = i + 1;
//        }
//
//        for (int dir : fin) {
//            if (dir == 0) seq.push_back('U');
//            else if (dir == 1) seq.push_back('R');
//            else if (dir == 2) seq.push_back('D');
//            else if (dir == 3) seq.push_back('L');
//        }
//        fin.clear();
//        f++;
//    }
//
//    cout << seq.size() << "\n";
//    for (char c : seq)
//        cout << c;
//    cout << "\n";

    return 0;
}