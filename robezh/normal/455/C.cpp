#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int MAXN = (int)3e5 + 500;

int n,m,q,a,b,c;
bool vis[MAXN];
int u[MAXN], dia[MAXN];
vector<int> G[MAXN];

int find(int i){
    return u[i] == i ? u[i] : u[i] = find(u[i]);
}

void unite(int i, int j){
    int fi = find(i), fj = find(j);
    u[fi] = fj;
    int d1 = dia[fj], d2 = dia[fi];
    dia[fj] = max(max(d1, d2), (d1+1)/2 + (d2+1)/2 + 1);
}

int dfs(int root, int v){
    u[v] = root;
    vis[v] = true;
    int fst = 0, sec = 0;
    for(int nxt : G[v]){
        if(!vis[nxt]){
            int now = 1 + dfs(root, nxt);
            if(now > fst){sec = fst, fst = now;}
            else if(now > sec){sec = now;}
        }
    }
    dia[root] = max(dia[root], fst + sec);

    return fst;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 0; i < MAXN; i++) u[i] = i;

    cin >> n >> m >> q;
    while(m--){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i, i);
    }

    while(q--){
        cin >> a;
        if(a == 2){
            cin >> b >> c;
            if(find(b) != find(c)) unite(b, c);
        }
        else{
            cin >> b;
            b = find(b);
            cout << dia[b] << endl;
        }
    }
}