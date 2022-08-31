#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuck0
#define y0 fuck1
#define x1 fuck2
#define y1 fuck3
#define st first
#define nd second
using namespace std;
typedef pair<int,int> pr;
typedef long long ll;
typedef long double ld;
const int N=3e6+5;
const ld eps=1e-12,inf=1e18;
int d,m,T;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d%d",&d,&m);
        int ans=1%m;
        for(ll i=2;i/2<=d;i<<=1){
            ll num=(min(i-1,1ll*d)-(i/2-1))%m;
            //printf("%lld\n",num);
            ans=(num+1)*ans%m;
        }
        ans=(ans-1+m)%m;
        printf("%d\n",ans);
    }
    return 0;
}