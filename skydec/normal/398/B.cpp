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
db f[2005][2005];
int n,m;
bool h[2005],l[2005];
inline void dp(){
	rep(i,0,n)rep(j,0,n)if(i+j!=0){
		int s11,s10,s01,s00;
		//10
		s00=(n-i)*(n-j);
		s10=i*(n-j);
		s01=(n-i)*j;
		s11=i*j;
		if(s10)f[i][j]+=(f[i-1][j]+1)*(s10*1./(n*1.*n));
		if(s01)f[i][j]+=(f[i][j-1]+1)*(s01*1./(n*1.*n));
		if(s11)f[i][j]+=(f[i-1][j-1]+1)*(s11*1./(n*1.*n));
		f[i][j]+=(s00*1./(n*1.*n));
		f[i][j]*=(n*1.*n)/(n*1.*n-s00);
	}
}
int main(){
	scanf("%d%d",&n,&m);int x,y;x=y=0;
	dp();
	rep(i,1,m){
		int a,b;scanf("%d%d",&a,&b);
		if(!h[a])x++;
		if(!l[b])y++;
		h[a]=l[b]=1;
	}
	printf("%.7lf\n",f[n-x][n-y]);
	return 0;
}