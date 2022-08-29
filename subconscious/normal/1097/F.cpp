#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define rev(i,n) for(int i=n;i;--i)
#define x0 fuck
#define y0 fuxk
#define y1 fxck
#define x1 fxxk
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e5+5,inf=0x3f3f3f3f,MOD=1e9+7;
const ld eps=1e-9;
int n,q;
bitset<7005>a[N],b[7005],c[7005];
int mu[7005];
int main(){
    mu[1]=1;
    for(int i=2;i<=7000;++i){
        bool f=0;
        for(int j=2;1ll*j*j<=i;++j)if(i%j==0){
            mu[i]=((i/j)%j==0)?0:mu[i/j];
            f=1;break;
        }
        if(!f)mu[i]=1;
    }
    //rep(i,100)printf("%d",mu[i]);
    scanf("%d%d",&n,&q);
    rep(i,7000)for(int j=1;j<=i;++j)if(i%j==0)b[i][j]=1;
    rep(i,7000)for(int j=1;1ll*i*j<=7000;++j)if(mu[j])c[i][i*j]=1;
    //rep(i,10)printf("%d",(int)c[4][i]);
    rep(i,n)a[i].reset();
    rep(i,q){
        int opt,x,y,z;
        scanf("%d",&opt);
        if(opt==1){
            scanf("%d%d",&x,&y);
            a[x]=b[y];
        }else if(opt==2){
            scanf("%d%d%d",&x,&y,&z);
            a[x]=a[y]^a[z];
        }else if(opt==3){
            scanf("%d%d%d",&x,&y,&z);
            a[x]=a[y]&a[z];
        }else if(opt==4){
            scanf("%d%d",&x,&y);
            printf("%c",((a[x]&c[y]).count()&1)?'1':'0');
        }
    }
    puts("");
}