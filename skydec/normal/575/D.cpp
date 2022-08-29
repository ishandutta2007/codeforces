#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
int main(){
	int n=1000;
	printf("%d\n",2*n);
	rep(i,1,n)printf("%d %d %d %d\n",i,1,i,2);
	per(i,n,1)printf("%d %d %d %d\n",i,1,i,2);
	return 0;
}