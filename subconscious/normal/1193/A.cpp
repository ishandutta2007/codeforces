#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
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
typedef __int128 i128;
typedef pair<int,int> pr;
typedef vector<int> vi;
const int N=18,mod=998244353;
int edg[1<<N],a[1<<N],cnt[1<<N],b[N+1][1<<N];
int n,m,tmp[N+1];
int main(){
    scanf("%d%d",&n,&m);
    //n=18,m=0;
    rep(i,m){
        int x,y;
        scanf("%d%d",&x,&y);
        --x,--y;
        edg[1<<x]|=1<<y,edg[1<<y]|=1<<x;
    }
    a[0]=1;cnt[0]=0;b[0][0]=1;
    for(int i=1;i<1<<n;++i){
        int lb=i&-i;
        a[i]=a[i-lb]&&((edg[lb]&i)==0);
        //printf("i:%d a[i]:%d\n",i,a[i]);
        cnt[i]=cnt[i-lb]+1;
        b[cnt[i]][i]=a[i];
    }
    rep(i,n+1)rep(j,n)for(int k=0;k<1<<n;++k)if(!(k&(1<<j)))
        (b[i][k|(1<<j)]+=b[i][k])%=mod;
    for(int p=0;p<1<<n;++p){
        tmp[0]=b[0][p];//==1!
        for(int i=1;i<=n;++i){
            tmp[i]=0;
            rep(j,i)tmp[i]=(tmp[i]-(ll)tmp[j]*b[i-j][p]%mod+mod)%mod;
        }
        rep(i,n+1)b[i][p]=tmp[i];//,printf("%d%c",b[i][p]," \n"[i+1==n]);
    }
    rep(i,n+1)rep(j,n)for(int k=0;k<1<<n;++k)if(!(k&(1<<j)))
        b[i][k|(1<<j)]=(b[i][k|(1<<j)]-b[i][k]+mod)%mod;
    int ans=(ll)b[n][(1<<n)-1]*m%mod*((mod+1)/2)%mod;
    if(n&1)ans=(mod-ans)%mod;
    printf("%d\n",ans);
    return 0;
}
/*

*/