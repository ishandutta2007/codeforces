#include <bits/stdc++.h>
#define rep(i,n) for(long long i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define x0 fuckcjb
#define y0 fuckyzc
#define x1 fuckshb
#define y1 fuckhel
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e6+5,mod=1e9+7;
vector<int>g[N];
int n,T,l[N],r[N];
ll a[2][N];
void dfs(int x,int fa){
    a[0][x]=a[1][x]=0;
    for(int v:g[x])if(v!=fa){
        dfs(v,x);
        a[0][x]+=max(a[0][v]+abs(l[x]-l[v]),a[1][v]+abs(l[x]-r[v]));
        a[1][x]+=max(a[0][v]+abs(r[x]-l[v]),a[1][v]+abs(r[x]-r[v]));
    }
}
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)g[i].clear();
        rep(i,n)scanf("%d%d",l+i,r+i);
        rep(i,n-1){
            int x,y;scanf("%d%d",&x,&y);
            g[x].pb(y),g[y].pb(x);
        }
        dfs(1,0);
        printf("%lld\n",max(a[0][1],a[1][1]));
    }
    return 0;
}