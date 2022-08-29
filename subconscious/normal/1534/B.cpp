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
const int N=4e5+5,mod=1e9+7;
int a[N];
int n,T;
ll ans;
int main(){
    scanf("%d",&T);
    rep(Cas,T){
        scanf("%d",&n);
        rep(i,n)scanf("%d",a+i);
        a[0]=a[n+1]=0;
        ans=0;
        rep(i,n){
            int dif=max(a[i]-max(a[i-1],a[i+1]),0);
            ans+=dif;
            a[i]-=dif;
        }
        for(int i=0;i<=n;++i)ans+=abs(a[i]-a[i+1]);
        printf("%lld\n",ans);
    }
    return 0;
}