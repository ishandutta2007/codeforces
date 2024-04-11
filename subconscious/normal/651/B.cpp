#include <algorithm>
#include <cstdio>
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 1005
using namespace std;
int a[N],n,s=0,p=0,x;
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&x),++a[x];
	rep(i,1000){
		x=0;
		rep(j,1000)if(a[j]>0)--a[j],++x;
		if(x>1)s+=x-1;else break;
	}
	printf("%d\n",s);
	return 0;
}