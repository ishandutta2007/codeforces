#include <bits/stdc++.h>
using namespace std;

const int N = (int)3e5 + 500;
typedef long long ll;
typedef pair<int, int> P;

int n,m;
vector<int> G[N];
vector<P> qr[N];
ll dif[N], res[N];

void dfs(int v, int par, int depth, ll sum){
    sum -= dif[depth];
    for(auto p : qr[v]){
        sum += p.second;
        dif[min(N-1, depth + p.first + 1)] += p.second;
    }
    res[v] = sum;
    for(int nxt : G[v]){
        if(nxt != par){
            dfs(nxt, v, depth + 1, sum);
        }
    }
    for(auto p : qr[v]){
        sum -= p.second;
        dif[min(N-1, depth + p.first + 1)] -= p.second;
    }

}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int v, d, x;
        scanf("%d%d%d", &v, &d, &x);
        v--;
        qr[v].push_back({d, x});
    }
    dfs(0, -1, 0, 0);

    for(int i = 0; i < n; i++) printf("%I64d ", res[i]);
}