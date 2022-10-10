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

int d[10000], dist[10000][1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++)
        cin >> d[i];
    int g, r;
    cin >> g >> r;

    sort(d, d + m);
    memset(dist, -1, sizeof(dist));
    deque<pair<int, int>> dq;
    dq.push_back({0, 0});
    dist[0][0] = 0;
    while (!dq.empty()) {
        int pos = dq.front().first, timeLeft = dq.front().second;
        dq.pop_front();

        for (int i : {-1, 1})
            if (0 <= pos + i && pos + i < m && abs(d[pos] - d[pos+i]) <= (timeLeft == 0 ? g : timeLeft)) {
                int nt = (timeLeft == 0 ? g : timeLeft) - abs(d[pos] - d[pos+i]);
                if (dist[pos+i][nt] == -1) {
                    dist[pos+i][nt] = dist[pos][timeLeft] + (nt == 0);
                    if (nt == 0)
                        dq.push_back({pos + i, nt});
                    else
                        dq.push_front({pos + i, nt});
                }
            }
    }

    int ret = INT_MAX;
    for (int j=0; j<g; j++)
        if (dist[m-1][j] != -1)
            ret = min(ret, (g + r) * dist[m-1][j] + (j == 0 ? -r : g - j));

    cout << (ret == INT_MAX ? -1 : ret) << "\n";

    return 0;
}