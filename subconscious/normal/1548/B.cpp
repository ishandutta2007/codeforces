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
int T,n;
ll a[N],b[N];
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
pair<ll,int>q[N];
int top;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)scanf("%lld",a+i);
        rep(i,n-1)b[i]=abs(a[i]-a[i+1]);
        int ans=0;
        top=0;
        rep(i,n-1){
            rep(j,top)q[j].st=gcd(q[j].st,b[i]);
            q[++top]=mp(b[i],i);
            int now=0;
            rep(j,top)if(j==1||q[now].st!=q[j].st)q[++now]=q[j];
            top=now;
            rep(j,top)if(q[j].st>1)ans=max(ans,i-q[j].nd+1);
        }
        printf("%d\n",ans+1);
    }
    return 0;
}
/*

*/