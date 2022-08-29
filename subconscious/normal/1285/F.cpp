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
const int N=1e5+5;
int pri[N/3],mu[N],top;
bool isnp[N];
int n;
vi g[N];
bool in[N];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int sta[N],stp;
int t[N];
int main(){
    mu[1]=1;
    for(int i=2;i<N;++i){
        if(!isnp[i])
            pri[++top]=i,mu[i]=-1;
        for(int j=1;j<=top&&(ll)pri[j]*i<N;++j){
            isnp[pri[j]*i]=1;
            if(i%pri[j]==0)
                break;
            else
                mu[pri[j]*i]=-mu[i];
        }
    }
    for(int i=1;i<N;++i)
        for(int j=i;j<N;j+=i)
            g[j].pb(i);

    scanf("%d",&n);
    rep(i,n){
        int x;scanf("%d",&x);
        in[x]=1;
    }
    for(int i=1;i<N;++i)if(!in[i])
        for(int j=i;j<N;j+=i)
            if(in[j]){in[i]=1;break;}

    ll ans=0;
    stp=0;
    for(int i=N-1;i;--i)if(in[i]){
        if(ans==0){
            trav(u,g[i])
                ++t[u];
            sta[++stp]=i;
        }
        ll cnt=0;
        trav(u,g[i])
            cnt+=t[u]*mu[u];
        if(cnt==0)continue;
        for(;;){
            if(gcd(i,sta[stp])==1)
                --cnt;
            if(cnt==0)break;
            trav(u,g[sta[stp]])
                --t[u];
            --stp;
        }
        ans=max(ans,(ll)sta[stp]*i);
    }
    printf("%lld\n",ans);
    return 0;
}
/*
44
155 188 95 86 212 468 137 23 465 239 104 109 427 176 344 266 55 10 334 224 489 99 483 137 159 341 91 364 52 113 248 346 439 271 468 309 382 93 320 351 337 429 125 196

 
*/