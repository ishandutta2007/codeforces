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
int f[1100000];
int main(){
	memset(f,63,sizeof f);f[0]=0;int ufo=f[1];
	rep(i,4,1000000)f[i]=min(f[i-4]+1,f[i]);
	rep(i,7,1000000)f[i]=min(f[i-7]+1,f[i]);
	int n;scanf("%d",&n);
	if(f[n]==ufo){
		printf("-1\n");
		return 0;
	}
	rep(x,0,f[n])if(x*4+(f[n]-x)*7==n){
		rep(j,1,x)printf("4");
		rep(j,1,f[n]-x)printf("7");
		return 0;
	}
	return 0;
}