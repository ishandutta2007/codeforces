// by shik
#include <cstdio>
#include <algorithm>
using namespace std;
int a[400010],b[400010];
long long sa[400010],sb[400010];
int main()
{
	int t,n,m,i,j; long long na,nb;
	scanf("%d",&t);
	while ( t-- ) {
		scanf("%d",&n);
		m=2*n-1;
		na=nb=0;
		for ( i=1; i<=m; i++ ) {
			scanf("%d%d",a+i,b+i);
			sa[i+m]=sa[i]=sa[i-1]+a[i];
			sb[i+m]=sb[i]=sb[i-1]+b[i];
			a[i+m]=a[i];
			b[i+m]=b[i];
			na+=a[i];
			nb+=b[i];
		}
		for ( i=m+1; i<=2*m; i++ ) {
			sa[i]+=na;
			sb[i]+=nb;	
		}
		na=(na+1)/2;
		nb=(nb+1)/2;
		puts("YES");
		for ( i=0; i<m; i++ )
			if ( sa[i+n]-sa[i]>=na && sb[i+n]-sb[i]>=nb ) {
				printf("%d",i+1);
				for ( j=i+2; j<=i+n; j++ ) printf(" %d",j>m?j-m:j);	
				break;
			}
		puts("");
	}
	return 0;
}