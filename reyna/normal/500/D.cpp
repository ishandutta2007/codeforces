//In the name of God
#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdio>
using namespace std;
const int Maxn = 1e5 + 1e3;
vector<pair<int,int> > al[Maxn];
vector<pair<int,pair<int,int> > > edge;
int sub[Maxn];
int Edge[Maxn];
long double ans = 0;
int dfs(int v,int p){
    int ret = 1;
    for(int i = 0; i < al[v].size();i++){
        int u = al[v][i].first;
        if(u == p)
            continue;
        ret += dfs(u,v);
    }
    sub[v] = ret;
    return ret;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n-1;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        al[--v].push_back(make_pair(--u,w));
        al[u].push_back(make_pair(v,w));
        edge.push_back(make_pair(w,make_pair(u,v)));
        Edge[i] = w;
    }
    dfs(0,-1);
    for(int i = 0; i < n-1;i++){
        int u = edge[i].second.first,v = edge[i].second.second;
        long double w = edge[i].first;
        long double num = min(sub[u],sub[v]);
        long double t = n - num;
        ans += (((t * (t - 1))/2)*num)*w*3;
        ans += (((num * (num - 1))/2)*t)*w*3;
    }
    int Q;
    scanf("%d",&Q);
    for(int i = 0; i < Q;i++){
        int edgenum,newW;
        scanf("%d%d",&edgenum,&newW);
        int u = edge[--edgenum].second.first,v = edge[edgenum].second.second;
        long double w = newW - Edge[edgenum];
        Edge[edgenum] = newW;
        long double num = min(sub[u],sub[v]);
        long double t = n - num;
        ans += (((t * (t - 1))/2)*num)*w*3;
        ans += (((num * (num - 1))/2)*t)*w*3;
        cout << setprecision(9) << fixed << (((long double)6 * ans/((long double)n * ((long double)n-1) * ((long double)n-2)))*(long double)2)/3 << endl;
    }
}