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
const int N=2e6+5,mod=1e9+7;
int a[N],n,m,q,ans;
set<int>g[N];
bool check(int x){
    if(g[x].size()==0)return 1;
    auto t=g[x].end();
    --t;
    if(*t<x)return 1;
    return 0;
}
int main(){
    scanf("%d%d",&n,&m);
    rep(i,m){
        int x,y;scanf("%d%d",&x,&y);
        g[x].insert(y);g[y].insert(x);
    }
    scanf("%d",&q);
    int ans=0;
    rep(i,n)ans+=check(i);
    rep(tim,q){
        int opt,x,y;
        scanf("%d",&opt);
        if(opt==1){
            scanf("%d%d",&x,&y);
            ans-=(int)check(x)+check(y);
            g[x].insert(y);g[y].insert(x);
            ans+=(int)check(x)+check(y);
        }else if(opt==2){
            scanf("%d%d",&x,&y);
            ans-=(int)check(x)+check(y);
            g[x].erase(y);g[y].erase(x);
            ans+=(int)check(x)+check(y);
        }else{
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*

*/