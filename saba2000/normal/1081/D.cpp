#include<bits/stdc++.h>
using namespace std;
vector<int> v[300009], l[300090];
int x[300009];
int sz[300009], S[300009];
int p[300009];
int f[300009];
int n,k,m,fl;
int par(int x){
    if(p[x] != x) p[x] =par(p[x]);
    return p[x];
}
void un(int x, int y){
    x =par(x); y = par(y);
    if(x == y) return;
    if(S[x] > S[y]) swap(x, y);
    p[x] = y;
    sz[y] += sz[x];
    if(sz[y] == k) fl= 1;
    S[y] += S[x];
}
main(){
    cin >> n >> m>> k;
    for(int i = 1; i <= k; i++){
        scanf("%d", &x[i]);
        f[x[i]] = 1;
    }
    for(int i = 1;i <= n; i++){
        if(f[i]) sz[i] =1;
        else sz[i] = 0;
        S[i] = 1;
        p[i] = i;
    }
    vector<pair<int,pair<int,int> > > E;
    for(int i = 1; i <= m; i++){
        int a, b,c;
        scanf("%d %d %d", &a, &b, &c);
        E.push_back({c,{a,b}});
    }
    sort(E.begin(), E.end());
    for(int i = 0; i < m; i++){
        un(E[i].second.first, E[i].second.second);
        if(fl){
            for(int j = 1; j <= k; j++)
                cout<<E[i].first<<" ";
            return 0;
        }
    }

}