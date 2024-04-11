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
char mp[105][105],s[1005];int x[180],y[180],sx,sy,dx,dy,tx,ty,n,m,k;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n){scanf("%s",mp[i]+1);rep(j,1,m)if(mp[i][j]<='z'&&mp[i][j]>='a'){x[mp[i][j]]=i;y[mp[i][j]]=j;mp[i][j]=1;}else mp[i][j]-='0';}
	scanf("%d%d%s%d%d",&sx,&sy,s+1,&tx,&ty);int len=strlen(s+1);
	rep(i,1,len){
		if(x[s[i]]>sx)dx=1;else if(x[s[i]]<sx)dx=-1;else dx=0;
		if(y[s[i]]>sy)dy=1;else if(y[s[i]]<sy)dy=-1;else dy=0;
		while((sx^x[s[i]])||(sy^y[s[i]])){
			if(mp[sx][sy]>k)goto pyc;k-=mp[sx][sy];sx+=dx;sy+=dy;
		}
		pyc:;
	}
	if(tx>sx)dx=1;else if(tx<sx)dx=-1;else dx=0;
	if(ty>sy)dy=1;else if(ty<sy)dy=-1;else dy=0;
	while((sx^tx)||(sy^ty)){
		if(mp[sx][sy]>k)goto dyc;k-=mp[sx][sy];sx+=dx;sy+=dy;
	}
	dyc:;
	printf("%d %d\n",sx,sy);
	return 0;
}