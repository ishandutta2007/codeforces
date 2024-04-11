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
const int N=1e6+5,mod=1e9+7;
int a[N],c0,c1,T,n;
int main(){
    scanf("%d",&T);
    rep(Cas,T){
        scanf("%d",&n);
        c0=0;
        rep(i,n){
            scanf("%d",a+i);
            a[i]%=2;
            c0+=(a[i]==0);
        }
        c1=n-c0;
        ll ans=1e18;
        if(c1==c0+1||c1==c0){
            int cnt=0;
            ll now=0;
            rep(i,n)if(a[i]==1){
                ++cnt;
                now+=abs(i-(cnt*2-1));
            }
            ans=min(ans,now);
        }
        if(c0==c1+1||c0==c1){

            int cnt=0;
            ll now=0;
            rep(i,n)if(a[i]==0){
                ++cnt;
                now+=abs(i-(cnt*2-1));
            }
            ans=min(ans,now);
        }
        if(ans==1e18)puts("-1");else printf("%lld\n",ans);
    }

    return 0;
}
/*


*/