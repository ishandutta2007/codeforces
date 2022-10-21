#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 22) + 500;

int n,m;
int num[N], res = 0;
bool hav[N];
bool vis1[N], vis2[N];

void dfs2(int v);

void dfs1(int v){
    vis1[v] = true;
    if(!vis2[v]) dfs2(v);
}

void dfs2(int v){
    vis2[v] = true;
    for(int i = 0; i < n; i++){
        int nxt = v|(1<<i);
        if(v+(1<<i) == nxt && !vis2[nxt]) dfs2(nxt);
    }
    int nxt = (1<<n) - 1 - v;
    if(hav[nxt] && !vis1[nxt]) dfs1(nxt);

}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &num[i]);
        hav[num[i]] = true;
    }
    for(int i = 0; i < m; i++){
        if(!vis1[num[i]]) res++, dfs1(num[i]);
    }
    cout << res;
}