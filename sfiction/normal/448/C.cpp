/*
ID: Sfiction
OJ: CF
PROB: 448C
*/
/*
?nO(n^2)
O(nlogn)
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=5000+100,INF=0x7fffffff;

int n;
int a[MAXN];

int paint(int l,int r,int times){
	int m=l;
	for (int i=l;i<=r;++i)
		if (a[m]>a[i])
			m=i;

	int ret=0;
	if (l<m)
		ret+=paint(l,m-1,a[m]);
	if (m<r)
		ret+=paint(m+1,r,a[m]);

	return min(r-l+1,ret+a[m]-times);
}

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;++i)
		scanf("%d",&a[i]);

	printf("%d",paint(0,n-1,0));
	return 0;
}