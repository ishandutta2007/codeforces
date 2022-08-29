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
const int N=3e6+5,mod=998244353;
int n,T,fra[N],rev[N];
char s[N];
int pw(int x,int y=mod-2){
    int s=1;
    for(;y;y>>=1,x=(ll)x*x%mod)
        if(y&1)s=(ll)s*x%mod;
    return s;
}
int main(){
    fra[0]=1;rep(i,N-1)fra[i]=(ll)fra[i-1]*i%mod;
    rev[N-1]=pw(fra[N-1]);for(int i=N-2;~i;--i)rev[i]=(ll)rev[i+1]*(i+1)%mod;
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        scanf("%s",s+1);
        int len=0,c1=0,cnt0=0;
        rep(i,n)if(s[i]=='1')++len;else c1+=len&1,len=0,++cnt0;
        c1+=len&1;
        int bal=(n-cnt0-c1)/2,bas=cnt0+1;
        //C(bal+bas-1,bas-1)
        int ans=(ll)fra[bal+bas-1]*rev[bas-1]%mod*rev[bal]%mod;
        printf("%d\n",ans);

    }
    return 0;
}
/*

*/