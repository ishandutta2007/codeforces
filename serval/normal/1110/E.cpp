#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1000005;
int n;
int a[N],b[N];
bool ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	ans=(a[1]==b[1])&&(a[n]==b[n]);
	for (int i=1;i<n;i++)
		a[i]-=a[i+1];
	for (int i=1;i<n;i++)
		b[i]-=b[i+1];
	sort(a+1,a+n);
	sort(b+1,b+n);
	for (int i=1;i<n;i++)
		ans&=a[i]==b[i];
	printf(ans?"Yes\n":"No\n");
	return 0;
}