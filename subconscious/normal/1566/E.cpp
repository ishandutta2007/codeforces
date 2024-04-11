#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
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
typedef vector<int> vi;
const int N=3e6+5,mod=1e9+7;
int n,ans,T;
vi g[N];
int dfs(int x,int fa){
    int flag=0;
    trav(v,g[x])if(v!=fa){
        flag+=dfs(v,x);
    }
    if(flag>0){
        ans+=flag-1;
    }
    return flag>0?0:1;
}
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)g[i].clear();
        rep(i,n-1){
            int x,y;scanf("%d%d",&x,&y);
            g[x].pb(y),g[y].pb(x);
        }
        ans=0;
        int cnt=dfs(1,0);
        if(cnt==0){
            ++ans;
        }else{
            ++ans;
        }
        printf("%d\n",ans);
    }

    return 0;
}
/*
XFOF.XFOFX
XFOFXFOF
6+10+12
9+7
*/