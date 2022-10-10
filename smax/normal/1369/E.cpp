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

int w[100000], s[100000];
bool visited[200000];
vector<pair<int, int>> has[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> w[i];
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        s[x]++;
        s[y]++;
        has[x].emplace_back(y, i);
        has[y].emplace_back(x, i);
    }

    queue<int> q;
    for (int i=0; i<n; i++)
        if (s[i] <= w[i])
            q.push(i);

    vector<int> ret;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto &p : has[u])
            if (!visited[p.second]) {
                visited[p.second] = true;
                ret.push_back(p.second + 1);
                if (--s[p.first] == w[p.first])
                    q.push(p.first);
            }
    }

    if (ret.size() < m)
        cout << "DEAD\n";
    else {
        cout << "ALIVE\n";
        reverse(ret.begin(), ret.end());
        for (int x : ret)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}