#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
int n;
inline int Pow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%n)if(b&1)c=c*1ll*a%n;
	return c;
}
int main(){
	scanf("%d",&n);
	if(n==1){
		printf("YES\n");
		printf("1\n");
		return 0;
	}
	if(n==4){
		printf("YES\n");
		printf("1\n3\n2\n4");
		return 0;
	}
	for(int i=2;i*i<=n;i++)if(n%i==0){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	rep(i,1,n-1){
		if(i==1)printf("1\n");
		else printf("%d\n",i*1ll*Pow(i-1,n-2)%n);
	}
	printf("%d\n",n);
	return 0;
}