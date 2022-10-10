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

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    long long power = 1, fact = 1;
    for (int i=1; i<=n; i++) {
        if (i < n) power = power * 2 % MOD;
        fact = fact * i % MOD;
    }

    fact -= power;
    if (fact < 0)
        fact += MOD;
    cout << fact << "\n";

//    vector<int> perm(n);
//    iota(perm.begin(), perm.end(), 0);
//    int ret = 0;
//    do {
//        vector<vector<int>> adj(n);
//        for (int i=0; i<n; i++) {
//            for (int j=i-1; j>=0; j--)
//                if (perm[j] > perm[i]) {
//                    adj[i].push_back(j);
//                    adj[j].push_back(i);
//                    break;
//                }
//            for (int j=i+1; j<n; j++)
//                if (perm[j] > perm[i]) {
//                    adj[i].push_back(j);
//                    adj[j].push_back(i);
//                    break;
//                }
//        }
//        for (int i=0; i<n; i++) {
//            sort(adj[i].begin(), adj[i].end());
//            adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
//        }
//        vector<bool> visited(n);
//        function<bool (int, int)> dfs = [&] (int u, int p) {
//            visited[u] = true;
//            bool ret = false;
//            for (int v : adj[u]) {
//                if (visited[v])
//                    ret |= (v != p);
//                else
//                    ret |= dfs(v, u);
//            }
//            return ret;
//        };
//        bool cur = false;
//        for (int i=0; i<n; i++)
//            if (!visited[i])
//                cur |= dfs(i, -1);
//        ret += cur;
//    } while (next_permutation(perm.begin(), perm.end()));
//
//    cout << ret << "\n";

    return 0;
}