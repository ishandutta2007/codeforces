#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define jsb 1000000007
inline void add(int &a,int b){a+=b;if(a>=jsb)a-=jsb;}
#define MAXN 110000
int f[MAXN][2];int pre[MAXN];int sum[MAXN];
int mi[MAXN][3];int mo[3];int suf[MAXN][3];int ht[3];
char s[MAXN],t[MAXN];int n,m;int base[3];
inline bool ck(int l,int r,int k){
	int u=suf[r][k];
	u=(u-suf[l-1][k]*1ll*mi[r-l+1][k]%mo[k])%mo[k];u=(u+mo[k])%mo[k];
	if(u==ht[k])return 1;
	return 0;
}
int main(){
	scanf("%s",s+1);scanf("%s",t+1);
	n=strlen(s+1);m=strlen(t+1);
	mo[0]=233333;
	mo[1]=100007;
	mo[2]=999999997;
	base[0]=1593572;
	base[1]=9127120;
	base[2]=2333333;
	mi[0][0]=mi[0][1]=mi[0][2]=1;
	rep(i,1,n)rep(j,0,2)mi[i][j]=mi[i-1][j]*1ll*base[j]%mo[j];
	rep(i,1,n)rep(j,0,2){
		suf[i][j]=suf[i-1][j]*1ll*base[j]%mo[j];suf[i][j]=(suf[i][j]+s[i])%mo[j];
		if(i<=m)ht[j]=ht[j]*1ll*base[j]%mo[j];ht[j]=(ht[j]+t[i])%mo[j];
	}
	memset(pre,-1,sizeof pre);f[0][0]=1;sum[0]=1;
	rep(i,m,n)if(ck(i-m+1,i,0)&&ck(i-m+1,i,1)&&ck(i-m+1,i,2))pre[i]=i-m;else pre[i]=pre[i-1];
	rep(i,1,n){
		if(pre[i]>=0)add(f[i][1],sum[pre[i]]);
		add(f[i][1],f[i-1][1]);
		add(f[i][0],f[i-1][0]);
		add(sum[i],sum[i-1]);
		add(sum[i],f[i][0]);
		add(sum[i],f[i][1]);
		//printf("%d %d\n",f[i][0],f[i][1]);
	}
	int res=0;res=f[n][1];
	printf("%d\n",res);return 0;
}