#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int r[10001], c[10001], dist[10001][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;

    int pos = -1;
    for (int i=0; i<k; i++) {
        cin >> r[i] >> c[i];
        if (r[i] == n && c[i] == m)
            pos = i;
    }
    if (pos == -1)
        pos = k;
    r[k] = n;
    c[k] = m;

    memset(dist, 127, sizeof(dist));
    deque<pair<int, int>> dq;
    dist[0][0] = 0;
    dq.push_back({0, 0});
    while (!dq.empty()) {
        auto p = dq.front();
        dq.pop_front();

        for (int i=0; i<=k-(pos!=k); i++)
            if (i != p.first && (abs(r[i] - r[p.first]) <= 2 || abs(c[i] - c[p.first]) <= 2)) {
                // approach with no light
                if (((abs(r[i] - r[p.first]) + abs(c[i] - c[p.first]) == 1) || (p.second == 1 && abs(r[i] - r[p.first]) == 1) || (p.second == 2 && abs(c[i] - c[p.first]) == 1)) && dist[p.first][p.second] < dist[i][0]) {
                    dist[i][0] = dist[p.first][p.second];
                    dq.push_front({i, 0});
                } else if (dist[p.first][p.second] + 1 < dist[i][0]) {
                    dist[i][0] = dist[p.first][p.second] + 1;
                    dq.push_back({i, 0});
                }
                // approach with row light
                if (abs(r[i] - r[p.first]) <= 1) {
                    if (p.second == 1 && r[i] == r[p.first] && dist[p.first][p.second] < dist[i][1]) {
                        dist[i][1] = dist[p.first][p.second];
                        dq.push_front({i, 1});
                    } else if (dist[p.first][p.second] + 1 < dist[i][1]) {
                        dist[i][1] = dist[p.first][p.second] + 1;
                        dq.push_back({i, 1});
                    }
                }
                // approach with column light
                if (abs(c[i] - c[p.first]) <= 1) {
                    if (p.second == 2 && c[i] == c[p.first] && dist[p.first][p.second] < dist[i][2]) {
                        dist[i][2] = dist[p.first][p.second];
                        dq.push_front({i, 2});
                    } else if (dist[p.first][p.second] + 1 < dist[i][2]) {
                        dist[i][2] = dist[p.first][p.second] + 1;
                        dq.push_back({i, 2});
                    }
                }
            }
    }

    int ret = min(dist[pos][1], dist[pos][2]);
    if (pos != k)
        ret = min(ret, dist[pos][0]);

    cout << (ret > n * m ? -1 : ret) << "\n";

    return 0;
}