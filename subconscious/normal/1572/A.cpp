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
const int N=1e6+5,mod=998244353;
vi g[N];
int n,T,cnt[N],ans[N];
vi sta;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)g[i].clear();
        rep(i,n){
            int k;scanf("%d",&k);
            rep(j,k){
                int x;scanf("%d",&x);
                g[x].pb(i);
            }
            cnt[i]=k;
            ans[i]=0;
        }
        sta.clear();
        rep(i,n)if(cnt[i]==0)sta.pb(i),ans[i]=1;
        int s=0;
        for(;;){
            vi tmp;
            trav(u,sta){
                //printf("%d\n",u);
                trav(v,g[u]){
                    //printf("%d %d\n",u,v);
                    --cnt[v];ans[v]=max(ans[v],ans[u]+(v<u));
                    if(cnt[v]==0)tmp.pb(v);
                }
            }
            if(tmp.size()==0)break;
            sta=tmp;
        }
        bool flag=1;
        rep(i,n)if(cnt[i]!=0){flag=0;break;}
        rep(i,n)s=max(s,ans[i]);
        if(!flag)s=-1;
        printf("%d\n",s);
    }
    return 0;
}
/*
2 5 2
1 3 6
2 6 4
2 4 2
5 4 3
1 6 3
*/