#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=2e6+5,mod=998244353;
const ld eps=1e-10;
int a[N],b[N],n,T;
vector<int>g[N];
vector<int>bg,ed;
bool cmp(int x,int y){return g[x].size()>g[y].size();}
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)g[i].clear();
        rep(i,n)scanf("%d",a+i),b[i]=a[i],g[a[i]].pb(i);
        bg.clear();
        rep(i,n)if(g[i].size()>1){
            sort(g[i].begin(),g[i].end(),cmp);
            for(int j=0,siz=g[i].size();j+1<siz;++j)a[g[i][j]]=0;
        }else if(g[i].size()==0)
            bg.pb(i);
        ed.clear();
        for(int v:bg){
            int x=v;while(a[x]!=0)x=a[x];
            ed.pb(x);
        }
        for(int i=0,siz=bg.size();i<siz;++i)a[ed[i]]=bg[(i+1)%siz];
        int ans=0;
        rep(i,n)ans+=(a[i]==b[i]);
        printf("%d\n",ans);
        rep(i,n)printf("%d%c",a[i]," \n"[i==n]);
    }
    return 0;
}
/*
*/