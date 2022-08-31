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
int n,m;
int main(){
	scanf("%d%d",&n,&m);int c=1;int a=3;int b=n;
	for(;b;b>>=1,a=a*1ll*a%m)if(b&1)c=c*1ll*a%m;
	c--;if(c<0)c+=m;
	printf("%d\n",c);
	return 0;
}