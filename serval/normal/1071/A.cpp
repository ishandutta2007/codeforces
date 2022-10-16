#include <cstdio>
using namespace std;
const int N=5000005;
long long a,b;
long long s,t,cnt;
bool ret[N];
int main()
{
	scanf("%lld%lld",&a,&b);
	s=t=0;
	while (t+(s+1)<=a+b)
	{
		s++;
		t+=s;
	}
	t=s;
	while (a&&s)
		if (a>=s)
		{
			a-=s;
			ret[s]=1;
			s--;
			cnt++;
		}
		else
		{
			ret[a]=1;
			a=0;
			cnt++;
		}
	printf("%lld\n",cnt);
	for (s=1;s<=t;s++)
		if (ret[s])
			printf("%lld ",s);
	printf("\n");
	printf("%lld\n",t-cnt);
	for (s=1;s<=t;s++)
		if (!ret[s])
			printf("%lld ",s);
	printf("\n");
	return 0;
}