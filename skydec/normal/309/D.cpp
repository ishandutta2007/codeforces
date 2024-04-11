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
int n,m;
LL res;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=m+1;i+i<=n+1;i++){
		if(i+m>n)break;
		LL sum=0;int k=m+1;
		for(int j=m+1;j+m<=n;j++){
			for(;k+m<=n;k++)
			if((j-2*i)*(n+1+k-2*i)<3*j*(k-n-1))break;
			sum+=n-k-m+1;
		}
		if(i+i<=n)res+=2ll*sum;else res+=sum;
	}
	printf("%I64d\n",res*3ll);
	return 0;
}