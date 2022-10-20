#include <bits/stdc++.h>
//#include <atcoder/all>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;
ll N, M;
using UnWeightedGraph = vector<vector<int>>;
template< typename G >
struct LowLink {
  const G &g;
  vector< int > used, ord, low;
  vector< int > articulation;
  vector< pair< int, int > > bridge;
 
  LowLink(const G &g) : g(g) {}
 
  int dfs(int idx, int k, int par) {
    used[idx] = true;
    ord[idx] = k++;
    low[idx] = ord[idx];
    bool is_articulation = false;
    int cnt = 0;
    for(auto &to : g[idx]) {
      if(!used[to]) {
        ++cnt;
        k = dfs(to, k, idx);
        low[idx] = min(low[idx], low[to]);
        is_articulation |= ~par && low[to] >= ord[idx];
        if(ord[idx] < low[to]) bridge.emplace_back(minmax(idx, (int) to));
      } else if(to != par) {
        low[idx] = min(low[idx], ord[to]);
      }
    }
    is_articulation |= par == -1 && cnt > 1;
    if(is_articulation) articulation.push_back(idx);
    return k;
  }
 
  virtual void build() {
    used.assign(g.size(), 0);
    ord.assign(g.size(), 0);
    low.assign(g.size(), 0);
    int k = 0;
    for(int i = 0; i < g.size(); i++) {
      if(!used[i]) k = dfs(i, k, -1);
    }
  }
};
vector<ll> edges[105000];
ll depth[105000];
vector<l_l> ans;
ll dp[105000];
void dfs(int now, int from) {
    vector<int> children;
    for(auto to : edges[now]) {
        if(from == to) continue;
        depth[to] = depth[now] + 1;
        dfs(to, now);
        children.push_back(to);
    }
    if(children.empty()) {
        dp[now] = now;
        return;
    }
    vector<int> v;
    for(auto c : children) {
        assert(dp[c] != -1);
        if(dp[c] == -1) continue;
        v.push_back(dp[c]);
    }
    assert(v.size() == children.size());
    sort(v.begin(), v.end(), [&](ll q, ll w){
        return depth[q] > depth[w];
    });
    if(depth[now] != 0) {
        if(v.size() % 2 == 0) {
            for(int i = 0; i + 2 < v.size(); i += 2) {
                //cerr << "A" << endl;
                ans.push_back({v[i], v[i+1]});
            }
            int n = v.size();
            if(abs(depth[now] - depth[v[n-1]]) <= 1) {
                dp[now] = v[n-2];
            } else {
                ans.push_back({v[n-2], v[n-1]});
                dp[now] = now;
            }
        } else {
            for(int i = 0; i + 1 < v.size(); i += 2) {
                //cerr << "B" << endl;
                ans.push_back({v[i], v[i+1]});
            }
            dp[now] = v.back();
        }
    } else {
        if(v.size() % 2 == 0) {
            for(int i = 0; i < v.size(); i += 2) {
                //cerr << "A" << endl;
                ans.push_back({v[i], v[i+1]});
            }
        } else {
            for(int i = 0; i + 1 < v.size(); i += 2) {
                //cerr << "B" << endl;
                ans.push_back({v[i], v[i+1]});
            }
            int n = v.size();
            if(abs(depth[now] - depth[v[n-1]]) > 1) {
                ans.push_back({v[n-1], now});
            }
        }
    }
    //cerr << "dfs: " << now << " " << depth[now] << " " << dp[now] << endl;
}

void solve() {
    //cerr << "------------------" << endl;
    ans.clear();
    UnWeightedGraph g(N);
    for(int i = 0; i < N; i++) {
        edges[i].clear();
        depth[i] = -1;
        dp[i] = -1;
    }
    for(int i = 0; i < M; i++) {
        int S;
        cin >> S;
        vector<int> a(S);
        for(int j = 0; j < S; j++) {
            cin >> a[j];
            a[j]--;
        }
        for(int j = 0; j + 1 < S; j++) {
            g[a[j]].push_back(a[j+1]);
            g[a[j+1]].push_back(a[j]);
        }
    }
    LowLink<UnWeightedGraph> LL(g);
    LL.build();
    for(auto e : LL.bridge) {
        //cerr << e.first << " " << e.second << endl;
        edges[e.first].push_back(e.second);
        edges[e.second].push_back(e.first);
    }
    for(int i = 0; i < N; i++) {
        if(depth[i] != -1) continue;
        depth[i] = 0;
        dfs(i, -1);
    }
    cout << ans.size() << endl;
    for(auto e : ans) {
        cout << e.first + 1 << " " << e.second + 1 << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(cin >> N >> M) {
        if(N == 0 and M == 0) break;
        solve();
    }
    return 0;
}