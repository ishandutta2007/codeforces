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
int a[N],b[N],f[N];
int n,T;
int fa(int x){return f[x]==x?x:f[x]=fa(f[x]);}
int main(){
    scanf("%d",&T);
    rep(Cas,T){
        scanf("%d",&n);
        rep(i,n)scanf("%d",a+i);
        rep(i,n)scanf("%d",b+i);
        rep(i,n)f[i]=i;
        rep(i,n)a[i]=fa(a[i]),b[i]=fa(b[i]),f[a[i]]=b[i];
        int s=0;
        rep(i,n)if(f[i]==i)++s;
        int ans=1;
        rep(i,s)ans=(ans<<1)%mod;
        printf("%d\n",ans);
    }
    return 0;
}