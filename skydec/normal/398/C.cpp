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
	if(n==5){
		printf("1 3 1\n1 2 2\n2 4 1\n4 5 1\n3 4\n3 5\n");
		return 0;
	}
	rep(i,1,n/2)printf("%d %d %d\n",i,i+n/2,1);
	printf("%d %d %d\n",n/2+1,n/2+2,1);
	rep(i,n/2+2,n-1)printf("%d %d %d\n",i,i+1,i-n/2+1);
	rep(i,2,n/2)printf("%d %d\n",1,i);
	printf("2 3\n");
	return 0;
}