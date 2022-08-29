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
const int N=1e6+5,mod=998244353;
int n,x[N],y[N],s[N],f[N],S[N];
int main(){
    scanf("%d",&n);
    rep(i,n)scanf("%d%d%d",x+i,y+i,s+i);
    rep(i,n){
        int p=lower_bound(x+1,x+n+1,y[i])-x;
        f[i]=((x[i]-y[i]+mod)%mod+(S[i-1]-S[p-1]+mod)%mod)%mod;
        S[i]=(S[i-1]+f[i])%mod;
    }
    int ans=(x[n]+1)%mod;
    rep(i,n)if(s[i]==1)ans=(ans+f[i])%mod;
    printf("%d\n",ans);
    return 0;
}