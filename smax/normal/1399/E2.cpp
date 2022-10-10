#include <bits/stdc++.h>
using namespace std;

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

int c[100005];
long long w[100005], mult[100005], sz[100005];
vector<pair<int, int>> adj[100005];

struct cmp {
    bool operator () (int a, int b) {
        if ((w[a] + 1) / 2 * mult[a] == (w[b] + 1) / 2 * mult[b])
            return a < b;
        return (w[a] + 1) / 2 * mult[a] < (w[b] + 1) / 2 * mult[b];
    }
};

int dfs(int u, int p) {
    sz[u] = 0;
    bool isLeaf = true;
    for (auto &e : adj[u])
        if (e.first != p) {
            isLeaf = false;
            sz[u] += dfs(e.first, u);
            mult[e.second] = sz[e.first];
        }
    sz[u] += isLeaf;
    return sz[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long s;
        cin >> n >> s;
        for (int i=0; i<n; i++)
            adj[i].clear();
        for (int i=0; i<n-1; i++) {
            int u, v;
            cin >> u >> v >> w[i] >> c[i];
            u--, v--, c[i]--;
            adj[u].emplace_back(v, i);
            adj[v].emplace_back(u, i);
        }

        dfs(0, -1);
        vector<vector<long long>> bleh(2);
        long long tot = 0;
        for (int i=0; i<n-1; i++) {
            tot += w[i] * mult[i];
            while (w[i] > 0) {
                bleh[c[i]].push_back((w[i] + 1) / 2 * mult[i]);
                w[i] /= 2;
            }
        }
        sort(bleh[0].rbegin(), bleh[0].rend());
        sort(bleh[1].rbegin(), bleh[1].rend());

//        priority_queue<int, vector<int>, cmp> pq;
//        long long tot = 0;
//        for (int i=0; i<n-1; i++) {
//            tot += w[i] * mult[i];
//            pq.push(i);
//            DEBUG(i, w[i], mult[i])
//        }
        long long ret = LLONG_MAX, cur = 0;
        int i = 0;
        while (i < bleh[0].size() && tot > s) {
            tot -= bleh[0][i];
            cur++;
            i++;
        }
        if (tot <= s) {
            ret = cur;
        }
        for (int j=0; j<bleh[1].size(); j++) {
            tot -= bleh[1][j];
            cur += 2;
            while (i - 1 >= 0 && tot + bleh[0][i-1] <= s) {
                tot += bleh[0][--i];
                cur--;
            }
            if (tot <= s)
                ret = min(ret, cur);
        }
//        while (tot > s) {
//            assert(!pq.empty());
//            int i = pq.top();
//            pq.pop();
//            ret++;
//            assert(w[i] > 0);
//            tot -= ((w[i] + 1) / 2) * mult[i];
//            w[i] /= 2;
//            if (w[i] > 0) {
//                pq.push(i);
//            }
//        }
        cout << ret << "\n";
    }

    return 0;
}