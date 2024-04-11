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
int a[N],n;
int main(){
    ll ans=0;
    scanf("%d",&n);
    rep(i,n)scanf("%d",a+i);
    for(int i=1;i<=n;i+=2){
        ll now=0,mi=1e18;
        for(int j=i+1;j<=n;j+=2){
            //1<=u<=a[i] 1<=v<=a[j] mi+u>=0 1<=now+u<=a[j]
            ll mii=1,maa=a[i];
            mii=max(mii,-mi);
            mii=max(mii,1-now);
            maa=min(maa,a[j]-now);
            ans+=max(0ll,maa-mii+1);
            if(j+2<=n){
                mi=min(mi,now-a[j]);
                now=now-a[j]+a[j+1];
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*


*/