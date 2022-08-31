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
int T,n,m,a[N],cnt[N];
int in[N];
vector<int>ans;
int main(){
    scanf("%d",&T);
    rep(Cas,T){
        scanf("%d%d",&n,&m);
        rep(i,n)scanf("%d",a+i);
        for(int i=0;i<n;++i)cnt[i]=0;
        rep(i,n)++cnt[(i-a[i]+n)%n];
        ans.clear();
        for(int i=0;i<n;++i)if(cnt[i]>=n-2*m){
            rep(i,n)in[i]=0;
            int scc=0;
            rep(j,n)if(!in[j]){
                int now=j;
                
                for(;;){
                    in[now]=1;
                    now=(a[now]+i-1)%n+1;
                    if(now==j)break;
                }
                ++scc;
            }
            if(n-scc<=m)ans.pb(i);
        }
        printf("%d",(int)ans.size());
        for(int v:ans)printf(" %d",v);
        puts("");
    }
    return 0;
}