#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
int dp[105][105][30];
int n,m,a,b;
char c;
vector<P> V[105];

int get(int u, int v, int t){
    if(dp[u][v][t] != -1) return dp[u][v][t];

    for(P nxt : V[u]){
        if(nxt.second >= t && !get(v,nxt.first,nxt.second)) return dp[u][v][t] = 1;
    }
    return dp[u][v][t] = 0;

}

int main(){
    for(int i = 0; i < 105; i++)
        for(int j = 0; j < 105; j++)
            fill(dp[i][j], dp[i][j]+30, -1);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        a--,b--,c-='a';
        V[a].push_back(P(b,c));
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf(get(i,j,0) ? "A" : "B");
        }
        printf("\n");
    }


}