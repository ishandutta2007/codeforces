#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator () (uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<gp_hash_table<int, null_type, custom_hash>> adj(n);
        for (int i=0; i<m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].insert(v);
            adj[v].insert(u);
        }

        queue<int> q;
        vector<int> deg(n), vis(n);
        // 0 - not visited, 1 - in queue, 2 - deleted
        for (int i=0; i<n; i++) {
            deg[i] = adj[i].size();
            if (deg[i] < k) {
                q.push(i);
                vis[i] = 1;
            }
        }
        vector<int> clique;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = 2;
            // executes m / (k - 1) times, takes k^2 to execute, only executes for k <= sqrt(m)
            // O(m sqrt(m))
            if (deg[u] == k - 1 && (long long) k * (k - 1) / 2 <= m) {
                clique.push_back(u);
                for (int v : adj[u])
                    if (vis[v] != 2)
                        clique.push_back(v);
                bool ok = true;
                for (int i=0; i<k; i++)
                    for (int j=i+1; j<k; j++)
                        if (adj[clique[i]].find(clique[j]) == adj[clique[i]].end()) {
                            ok = false;
                            break;
                        }
                if (ok)
                    break;
                clique.clear();
            }
            for (int v : adj[u])
                if (--deg[v] < k && vis[v] == 0) {
                    q.push(v);
                    vis[v] = 1;
                }
        }

        if (!clique.empty()) {
            assert((int) clique.size() == k);
            cout << "2\n";
            for (int u : clique)
                cout << u + 1 << " ";
            cout << "\n";
        } else {
            vector<int> ret;
            for (int i=0; i<n; i++)
                if (vis[i] == 0)
                    ret.push_back(i);
            if (ret.empty()) {
                cout << "-1\n";
            } else {
                cout << "1 " << ret.size() << "\n";
                for (int u : ret)
                    cout << u + 1 << " ";
                cout << "\n";
            }
        }
    }

    return 0;
}