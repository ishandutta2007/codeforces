#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 3e5 + 5;
const int INF = 1e9;
vector<int> adj[MAXN], ts;
int tin[MAXN], en[MAXN], curt;
bool dag;

void dfs(int s, int p = -1) {
    tin[s] = ++curt;
    for(auto v : adj[s]) {
        if(tin[v] && !en[v]) {
            //cout << s << " -> " << v << endl;
            dag = false;
            return;
        }
        if(!tin[v])
            dfs(v, s);
    }
    en[s] = 1;
    ts.push_back(s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v;
    vector<vector<int>> g(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> g[i][j];
            if(g[i][j] > -1)
                v.push_back(g[i][j]);
        }
    }
    map<int, int> to;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i = 0; i < v.size(); i++) {
        //cout << v[i] << " -> " << i << endl;
        to[v[i]] = i;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] > -1)
                g[i][j] = to[g[i][j]];
            else
                g[i][j] = INF;
        }
    }
    /*for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << g[i][j] << " ";
        cout << endl;
    }*/
    int cur = 0;
    for(int i = 0; i < n; i++) {
        //cout << i << endl;
        vector<ii> nums;
        for(int j = 0; j < m; j++)
            nums.push_back({g[i][j], j});
        sort(nums.begin(), nums.end());
        cur += 2;
        for(int j = 0; j < m; j++) {
            auto p = nums[j];
            if(p.first == INF)
                break;
            if(j > 0 && nums[j].first != nums[j - 1].first)
                cur++;
            adj[p.second].push_back(m + cur);
            adj[m + cur - 1].push_back(p.second);
            //cout << p.second << " -> " << m + cur << '\n';
            //cout << m + cur - 1 << " -> " << p.second << '\n';
        }
    }
    dag = true;
    for(int i = 0; i < MAXN; i++)
        if(!tin[i]) dfs(i);
    if(!dag) {
        cout << "-1\n";
        return 0;
    }
    reverse(ts.begin(), ts.end());
    for(auto x : ts)
        if(x < m) cout << x + 1 << " ";
    cout << '\n';
}