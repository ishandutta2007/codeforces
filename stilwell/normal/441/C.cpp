#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define N 310
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j,k,n,m,K,A,B;
int main() {
	scanf("%d%d%d",&n,&m,&K);
	i=j=1;
	for (k=K;k>1;k--) {
		if (j<m) printf("2 %d %d %d %d\n",i,j,i,j+1),i++;
		else printf("2 %d %d %d %d\n",i,j,i+1,j),i+=2;
		if (i>n) i=1,j+=2;
	}
	printf("%d ",n*m-2*(K-1));
	for (A=n;A>=i;A--) printf("%d %d ",A,j);
	if (j<m) For(A,i,n) printf("%d %d ",A,j+1);
	j+=2;
	for (;j<=m;j+=2) {
		for (k=n;k;k--) printf("%d %d ",k,j);
		if (j<m) For(k,1,n) printf("%d %d ",k,j+1);
	}
	printf("\n");
	//for(;;);
	return 0;
}