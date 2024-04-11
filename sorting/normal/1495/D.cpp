#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }

const int N = 400 + 3;
const int M = 600 + 3;
const int MOD = 998244353;

vector<int> adj[N], v[2 * N];
pair<int, int> e[M];
int n, m, d[N][N], c[N], root[N], ans[N][N];

void bfs(int start){
    queue<int> q;
    q.push(start);
    fill(d[start] + 1, d[start] + 1 + n, INT_MAX);
    d[start][start] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int to: adj[u])
            if(d[start][to] > d[start][u] + 1){
                d[start][to] = d[start][u] + 1;
                q.push(to);
            }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> e[i].first >> e[i].second;
        adj[e[i].first].push_back(e[i].second);
        adj[e[i].second].push_back(e[i].first);
    }

    for(int i = 1; i <= n; ++i)
        bfs(i);

    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; ++j){
            ans[i][j] = 1;
            for(int idx = 0; idx <= 2 * n; ++idx)
                v[idx].clear();
            for(int idx = 1; idx <= n; ++idx){
                v[d[i][idx] + d[j][idx]].push_back(idx);
                c[idx] = d[i][idx] + d[j][idx];
            }
            bool first = true, ok = true;
            for(int sum = 0; sum <= 2 * n && ok; ++sum){
                if(v[sum].empty()) continue;
                if(first){
                    if(v[sum].size() != sum + 1){
                        ok = false;
                        break;
                    }
                    first = false;
                    for(int x: v[sum])
                        root[x] = x;
                    continue;
                }

                for(int x: v[sum]){
                    int cnt = 0;
                    root[x] = -1;
                    for(int to: adj[x]){
                       //cout << to << " " << x << " to x" << endl; 
                        if(c[to] >= sum) continue;
                        if(root[x] != -1 && root[x] != root[to]){
                            ok = false;
                            break;
                        }
                        else root[x] = root[to];
                        if(c[to] != sum - 2){
                            ok = false;
                            break;
                        }
                        ++cnt;
                    }
                    //cout << x << " " << cnt << " x cnt" << endl;
                    ans[i][j] = (ll)ans[i][j] * cnt % MOD; 
                }
            }
            ans[j][i] = ans[i][j];
            if(!ok){
                ans[i][j] = 0;
                ans[j][i] = 0;
                continue;
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}