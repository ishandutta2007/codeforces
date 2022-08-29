#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=1015;
int b[N][N];
char c[N];
int n;
char a[N];
int w[15];
int len=0;
int sa[N],rk[N];
int tsa[N],trk[N];
int sum[15];
int f[2][N];
int cost[N][12][2];
int dj[11][N];
int lp[N];
int dp(){
    rep(i,1,n)sa[i]=i;
    rep(i,1,n)rk[sa[i]]=i;

    rep(i,0,n)f[0][i]=f[1][i]=-1000000000;
    int now=0;
    f[0][0]=0;
    rep(bit,1,1005){
        rep(i,0,n)f[now^1][i]=-1000000000;
        memset(cost,0,sizeof cost);
        rep(i,1,n){
            rep(j,0,9)rep(k,0,1){
                if((bit<=max(lp[sa[i]],len))||(bit==max(lp[sa[i]],len)+1&&((b[sa[i]][bit]+j+k)%10!=0)))
                cost[i][j][k]=cost[i-1][j][k]+w[(b[sa[i]][bit]+j+k)%10];
                else cost[i][j][k]=cost[i-1][j][k];
            }
        }
        memset(sum,0,sizeof sum);
        rep(i,1,n)sum[b[i][bit]]++;
        per(i,8,0)sum[i]+=sum[i+1];
        per(i,n,1)tsa[sum[b[sa[i]][bit]]--]=sa[i];
        rep(i,1,n)trk[tsa[i]]=i;
        rep(i,0,9){
            int dc=0;
            while(dc<n&&b[tsa[dc+1]][bit]>i)++dc;
            rep(j,0,n){
                while(dc<n&&rk[tsa[dc+1]]<=j&&b[tsa[dc+1]][bit]==i)++dc;
                dj[i][j]=dc;
            }
        }
        rep(i,0,n)if(f[now][i]>=0){
            rep(v,0,9){
                if(v>0&&bit>len)continue;
                if(bit<=len&&a[bit]!='?'&&(a[bit]-'0'!=v))continue;
                if(bit==len&&v==0)continue;
                f[now^1][dj[9-v][i]]=max(f[now^1][dj[9-v][i]],f[now][i]+cost[i][v][1]+cost[n][v][0]-cost[i][v][0]);
            }
        }
        now^=1;
        rep(i,1,n)sa[i]=tsa[i],rk[i]=trk[i];
    }
    return f[now][0];
}
int main(){
    scanf("%s",a+1);
    n=strlen(a+1);
    len=n;
    rep(i,1,n)if(i<n+1-i)swap(a[i],a[n+1-i]);
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%s",c+1);
        int m=strlen(c+1);
        lp[i]=m;
        rep(j,1,m)b[i][j]=c[m+1-j]-'0';
    }
    rep(i,0,9)scanf("%d",&w[i]);
    printf("%d\n",dp());
    return 0;
}