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
int main(){
	int n;scanf("%d",&n);
	if(n<5){
		printf("No solution\n");
		return 0;
	}
	db xta=2.*acos(-1.0)/n;
	db l,now,x,y;l=100;now=x=y=0;
	rep(i,1,n-1){
		if(i^1){now+=xta;x+=l*cos(now);y+=l*sin(now);l+=0.002;}
		printf("%.5lf %.5lf\n",x,y);
	}
	now+=xta;
	printf("%.5lf 0\n",x-y/tan(now));
	return 0;
}