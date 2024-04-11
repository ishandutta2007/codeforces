#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,i,a[2005],j;
int main()
{
	 scanf("%d",&n);
	 for (i=1;i<=n;++i) scanf("%d",&a[i]);
	 for (i=1;i<=n;++i)
	 {
	 	  int sum=1;
	   for (j=1;j<=n;++j)
	     if (a[i]<a[j]) ++sum;
	    printf("%d ",sum);
	}
}