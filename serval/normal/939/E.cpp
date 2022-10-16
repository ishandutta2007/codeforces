#include <cstdio>
using namespace std;
int q,i,j,t,st,qt;
long long s[500005];
long long sum;
int main()
{
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d",&t);
		if (t==2)
		{
			printf("%.8lf\n",s[st]*1.0-(s[st]+sum)*1.0/(qt+1));
			continue;
		}
		scanf("%I64d",&s[++st]);
		while (qt+1<st&&s[qt+1]*(qt+1)<sum+s[st])
		{
			qt++;
			sum+=s[qt];
		}
	}
	return 0;
}