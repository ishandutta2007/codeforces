#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
int p[3005];
int f[3005][3005];
int suf[3005];int yd[3005];
int n,k;
inline void Min(int &x,int y){
	if(y<x)x=y;
}
int main()
{
	scanf("%d%d",&n,&k);
	rep(i,1,n){scanf("%d",&p[i]);p[i]=100-p[i];}
	per(i,n,1){
		suf[i]=(p[i]<100);
		suf[i]|=suf[i+1];
		yd[i]=(p[i]==0);
		yd[i]|=yd[i+1];
	}
	memset(f,63,sizeof f);
	f[1][2]=0;
	rep(i,1,n)rep(j,i+1,n){
		if(p[i]<100&&suf[j])Min(f[j+1][j+2],f[i][j]+1);
		if(p[i]<100&&!yd[j])Min(f[i][j+1],f[i][j]+1);
		if(suf[j]&&p[i]!=0)Min(f[j][j+1],f[i][j]+1);
	}
	int res=0;
	rep(i,1,n+1)rep(j,1,n+2)if(f[i][j]<=k)res++;
	printf("%d\n",res);
	return 0;
}