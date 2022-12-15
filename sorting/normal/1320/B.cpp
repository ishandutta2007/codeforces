#include <bits/stdc++.h>

using namespace std;

const int k_N = 2e5 + 7;
const int k_Inf = 1e9;

int n, m;
vector<int> adjacent[k_N];

int k, p[k_N];

int dist[k_N], cnt_prev[k_N];

void bfs(int start){
    queue<int> q;
    q.push(start);

    for(int i = 1; i <= n; ++i){
        dist[i] = k_Inf;
        cnt_prev[i] = 0;
    }

    dist[start] = 0;
    cnt_prev[start] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int to: adjacent[node]){
            int new_dist = dist[node] + 1;
            if(new_dist <= dist[to]){
                if(new_dist < dist[to])
                    q.push(to);
                dist[to] = new_dist;
                cnt_prev[to]++;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        adjacent[v].push_back(u);
    }

    cin >> k;
    for(int i = 0; i < k; ++i)
        cin >> p[i];

    bfs(p[k - 1]);

    //for(int i = 1; i <= n; ++i)
    //    cout << dist[i] << " - " << cnt_prev[i] << endl;

    int small = 0, big = 0;
    for(int i = 0; i < k - 1; ++i){
        int curr = p[i];
        int nxt = p[i + 1];

        if(dist[curr] != dist[nxt] + 1){
            small++;
            big++;
        }
        else{
            if(cnt_prev[curr] > 1)
                big++;
        }
    }

    cout << small << " " << big << "\n";
}