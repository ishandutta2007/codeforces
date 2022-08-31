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
int n;
inline int Pow(int a,int b){
	int c=1;for(;b;b>>=1,a=a*1ll*a%n)if(b&1)c=c*1ll*a%n;
	return c;
}
inline bool cao(int x){
	int p=n-1;
	for(int i=1;i*i<=n;i++)if(p%i==0){
		if(i<p&&Pow(x,i)==1)return 0;
		if(p/i<p&&Pow(x,p/i)==1)return 0;
	}
	return 1;
}
int main(){
	int x;scanf("%d%d",&n,&x);n++;
	for(int i=2;i*i<=n;i++)if(n%i==0){
		printf("-1\n");
		return 0;
	}
	for(x--;x>1;x--)if(cao(x)){
		printf("%d\n",x);
		return 0;
	}
	printf("-1\n");
	return 0;
}