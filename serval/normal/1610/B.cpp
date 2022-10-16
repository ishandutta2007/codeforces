#include <cstdio>
#include <algorithm>
using namespace std;
const int N=2e5+5;
int T;
int n,p,c;
int a[N],b[N];
bool solve()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	bool chk=1;
	for (int i=1;i<=n;i++)
		chk&=(a[i]==a[n-i+1]);
	if (chk)
		return 1;
	for (p=1;p<=n;p++)
		if (a[p]!=a[n-p+1])
			break;
	c=0;
	for (int i=1;i<=n;i++)
		if (a[i]!=a[p])
			b[++c]=a[i];
	chk=1;
	for (int i=1;i<=c;i++)
		chk&=(b[i]==b[c-i+1]);
	if (chk)
		return 1;
	c=0;
	for (int i=1;i<=n;i++)
		if (a[i]!=a[n-p+1])
			b[++c]=a[i];
	chk=1;
	for (int i=1;i<=c;i++)
		chk&=(b[i]==b[c-i+1]);
	if (chk)
		return 1;
	return 0;
}
int main()
{
	scanf("%d",&T);
	while (T--)
		if (solve())
			printf("YES\n");
		else
			printf("NO\n");
	return 0;
}