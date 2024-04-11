#include <stdio.h>
#include <algorithm>
using namespace std;
#define M 1000001
bool flag[M];
int n, m, a[M];

int main(){
	int i, j, k;
	scanf("%d", &n);
	for(i=0; i<n; i++)scanf("%d", &k),flag[k]=1;

	for(i=1; i<M; i++)if(!flag[i]&&flag[M-i])
		a[m++]=i;
	for(i=1; i*2<M; i++)if(!flag[i]&&!flag[M-i])
		a[m++]=i, a[m++]=M-i;
	sort(a, a+n);

	printf("%d\n", n);
	for(i=0; i<n; i++)printf("%d%c", a[i], i==n-1?10:32);

	return 0;
}