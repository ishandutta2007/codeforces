#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=5005;
int n,m;
int op[N];
char lv[N][1005],rv[N][1005];
bool isl[N],isr[N];
int bl[N],br[N];
map<string,int>num;
char na[N];
int f[3][2][2];
char ans[2][N];
int w[N];
int getv(int bit,int v){
    rep(i,1,n){
        int vl,vr;
        vl=vr=0;
        if(lv[i][1]<='1'&&lv[i][1]>='0'){
            w[i]=lv[i][bit]-'0';
            continue;
        }
        if(bl[i])vl=w[bl[i]];
        else if(isl[i])vl=v;
        else vl=lv[i][bit]-'0';

        if(br[i])vr=w[br[i]];
        else if(isr[i])vr=v;
        else vr=rv[i][bit]-'0';

        w[i]=f[op[i]][vl][vr];
    }
    int ans=0;
    rep(i,1,n)ans+=w[i];
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    rep(i,0,1)rep(j,0,1){
        f[0][i][j]=(i^j);
        f[1][i][j]=(i|j);
        f[2][i][j]=(i&j);
    }
    rep(i,1,n){
        scanf("%s",na+1);
        num[na+1]=i;
        scanf("%s",na+1);
        scanf("%s",na+1);
        if(strlen(na+1)==1&&na[1]=='?'){
            isl[i]=1;
        }
        else
        if(strlen(na+1)==m&&(na[1]=='0'||na[1]=='1')){
            rep(j,1,m)lv[i][j]=na[j];
            continue;
        }
        else{
            bl[i]=num[na+1];
        }
        scanf("%s",na+1);
        if(na[1]=='X')op[i]=0;
        else if(na[1]=='O')op[i]=1;
        else op[i]=2;
        scanf("%s",na+1);
        if(strlen(na+1)==1&&na[1]=='?'){
            isr[i]=1;
        }
        else
        if(strlen(na+1)==m&&(na[1]=='0'||na[1]=='1')){
            rep(j,1,m)rv[i][j]=na[j];
        }
        else{
            br[i]=num[na+1];
        }
    }
    rep(i,1,m){
        int x0=getv(i,0);
        int x1=getv(i,1);
        if(x0<x1)ans[0][i]=1,ans[1][i]=0;
        else if(x0==x1)ans[0][i]=ans[1][i]=0;
        else ans[0][i]=0,ans[1][i]=1;
    }
    rep(i,1,m)putchar(ans[1][i]+'0');
    puts("");
    rep(i,1,m)putchar(ans[0][i]+'0');
    puts("");
    return 0;
}