#include<bits/stdc++.h>
using namespace std;
long long ans[101010];
int main()
{
	long long a,b;
	int n;
	scanf("%d",&n);
	int pos = 0;
	for(int i = 1;i*i<=n;i++)
	{
		if(n%i) continue;
		int j = n/i;
		ans[pos++] = (long long)(2+(j-1)*i)*j/2;
		ans[pos++] = (long long)(2+(i-1)*j)*i/2;
	}
	sort(ans,ans+pos);
	int size = unique(ans,ans+pos) - ans;
	for(int i = 0;i<size;i++) printf("%lld\n",ans[i]);
	return 0;
}