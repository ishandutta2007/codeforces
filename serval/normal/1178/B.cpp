#include <cstdio>
using namespace std;
const int N=1e6+5;
char s[N];
long long ans;
int pre[N],suf[N];
int n;
int main()
{
	scanf("%s",s+1);
	for (n=1;s[n+1];n++);
	for (int i=1;i<=n;i++)
		pre[i]=pre[i-1]+(s[i]==s[i-1]&&s[i]=='v');
	for (int i=n;i;i--)
		suf[i]=suf[i+1]+(s[i]==s[i+1]&&s[i]=='v');
	for (int i=1;i<=n;i++)
		if (s[i]=='o')
			ans+=1ll*pre[i-1]*suf[i+1];
	printf("%lld\n",ans);
	return 0;
}