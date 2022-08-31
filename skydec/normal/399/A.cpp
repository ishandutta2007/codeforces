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
int n,p,k;
int main(){
	scanf("%d%d%d",&n,&p,&k);
	if(p-k>1){
		printf("<< ");
		rep(i,p-k,p-1)printf("%d ",i);
	}
	else rep(i,1,p-1)printf("%d ",i);
	printf("(%d) ",p);
	if(p+k<n){
		rep(i,p+1,p+k)printf("%d ",i);
		printf(">>");
	}
	else rep(i,p+1,n)printf("%d ",i);
	return 0;
}