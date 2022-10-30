#include<stdio.h>
#include<vector>
using namespace std;
#define N 1010
int a[N], n, x, y;
bool vis[N], fg[N];
vector <pair<int, int> > v[N], V;
vector <int> S;
void dfs(int x){
    vis[x] = 1;
    for(int i = 0; i < v[x].size(); i ++){
        if(fg[v[x][i].second]) continue;
        fg[v[x][i].second] = 1;
        if(vis[v[x][i].first]) V.push_back(make_pair(x, v[x][i].first));
        else dfs(v[x][i].first);
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i ++){
        scanf("%d %d", &x, &y);
        v[x].push_back(make_pair(y, i));
        v[y].push_back(make_pair(x, i));
    }
    for(int i = 1; i <= n; i ++){
        if(vis[i]) continue;
        S.push_back(i);
        dfs(i);
    }
    printf("%d\n", V.size());
    for(int i = 0; i < V.size(); i ++){
        printf("%d %d %d %d\n", V[i].first, V[i].second, S[0], S[i+1]);
    }
}