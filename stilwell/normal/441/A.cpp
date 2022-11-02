#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define N 100
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j,k,n,m,x;
int g[N];
int main() {
	scanf("%d%d",&n,&m);
	For(i,1,n) {
		scanf("%d",&k);
		int mi=1000000;
		For(j,1,k) scanf("%d",&x),mi=min(mi,x);
		if (mi<m) g[++*g]=i;
	}
	printf("%d\n",*g);
	For(i,1,*g) printf("%d ",g[i]);
	printf("\n");
	//for(;;);
	return 0;
}