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
map<pii,bool>fuck;
int n,m;char s[5];int x,y;LL ans;int dx,dy;
int main(){
	scanf("%d%d",&n,&m);scanf("%d%d",&x,&y);scanf("%s",s+1);
	if(s[1]=='U')dx=-1;else dx=1;
	if(s[2]=='L')dy=-1;else dy=1;
	int fis=0;int test=1000000;
	while(test--){
		pii now=pii(x,y);
		if(!fuck[now]){fuck[now]=1;fis++;}
		if(fis==n+m-2){
			printf("%I64d",ans+1);
			return 0;
		}
		int xl,yl,l;int ex,ey;
		if(dx==-1)xl=x-1;else xl=n-x;
		if(dy==-1)yl=y-1;else yl=m-y;
		if(xl<yl){ex=-dx;ey=dy;l=xl;}
		else if(xl>yl){ey=-dy;ex=dx;l=yl;}
		else{ex=-dx;ey=-dy;l=yl;}
		x+=dx*l;y+=dy*l;ans+=1ll*l;
		dx=ex;dy=ey;
	}
	printf("-1\n");
	return 0;
}