#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100050, LOG_N = 17;
const ll INF = (ll)2e18;
int root = 0;
int n,m,a,b,L;
ll S;

vector<int> G[N];
int parent[LOG_N][N];
ll sum[LOG_N][N];
int w[N], top[N];
int depth[N];

void dfs(int v, int p, int d){
    parent[0][v] = p;
    sum[0][v] = (p == -1 ? INF : w[p]);
    depth[v] = d;
    for(int nxt : G[v]){
        if(nxt != p) dfs(nxt, v, d+1);
    }
}

void init(int V){
    dfs(root, -1, 0);
    for(int k = 0; k+1 < LOG_N; k++){
        for(int v = 0; v < V; v++){
            if(parent[k][v] < 0) parent[k+1][v] = -1, sum[k+1][v] = INF;
            else parent[k+1][v] = parent[k][parent[k][v]], sum[k+1][v] = min(INF, sum[k][v] + sum[k][parent[k][v]]);
        }
    }
}

int tot_sum = 0;

int dfs(int v){
    int res = N;

    for(int nxt : G[v]){
        res = min(res, dfs(nxt));
    }
    if(res > depth[v]){
        tot_sum += 1;
        return top[v];
    }
    return res;
}



int main(){
//    cin.tie(0);
//    ios::sync_with_stdio(false);

    cin >> n >> L >> S;
    for(int i = 0; i < n; i++){
        cin >> w[i];
        if(w[i] > S) return !printf("-1");
    }
    for(int i = 1; i < n; i++){
        int x;
        scanf("%d", &x); x--;
        G[x].push_back(i);
    }
    init(n);
    for(int i = 0; i < n; i++){
        ll cur_sum = w[i];
        int cur = i, cur_len = 1;
        for(int j = LOG_N - 1; j >= 0; j--){
            if(cur_sum + sum[j][cur] <= S && cur_len + (1 << j) <= L){
                cur_sum += sum[j][cur];
                cur = parent[j][cur];
                cur_len += (1 << j);
            }

        }
        top[i] = depth[cur];
        //cout << i << ": " << cur << endl;
    }
    dfs(0);
    cout << tot_sum << endl;
}