#include <iostream>
using namespace std;
const int N=200000+10;
const int B=19981027;
int n,m,a[N],b[N],pos[N],pw[N],sum[N<<2],cnt[N<<2],ha,hb;
void update(int l,int r,int rt,int x,int sgn){
    if(l==r){
        cnt[rt]+=sgn;
        sum[rt]+=sgn*b[x]; return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)update(l,mid,rt<<1,x,sgn);
    else update(mid+1,r,rt<<1|1,x,sgn);
    cnt[rt]=cnt[rt<<1]+cnt[rt<<1|1];
    sum[rt]=sum[rt<<1]*pw[cnt[rt<<1|1]]+sum[rt<<1|1];
}
int main(){
    pw[0]=1; for(int i=1;i<N;i++)pw[i]=pw[i-1]*B;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)scanf("%d",&b[i]),pos[b[i]]=i;
    ha=0; for(int i=1;i<=n;i++) ha=ha*B+a[i], hb=hb*B+1;
    int ans=0;

    //printf("ha=%d\n", ha);
    for(int i=1;i<=m;i++){
        update(1,m,1,pos[i],+1); //printf("insert %d\n", pos[i]);
        if(i>n){
            update(1,m,1,pos[i-n],-1); ha+=hb;
        }
        //printf("sum=%d\n", sum[1]);
        if(sum[1]==ha) ans++;
    }
    cout<<ans<<endl;
}