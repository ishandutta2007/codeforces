#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1; char ch = getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
typedef long long ll;
const int M = 100016, MOD = 1000000007;
int main(void)
{
	#ifdef _LITTLEFALL_
	freopen("in.txt","r",stdin);
	#endif

	int n = read();
	for(ll x=2; x*x<=n; x++) if(n%x==0 && __gcd(x, n/x)==1)
	{
		ll y = n/x;
		for(ll cy=1; cy*y<=n-1; ++cy)
		{
			if((n-1 - cy*y)%x==0)
			{
				ll cx = (n-1-cy*y)/x;
				printf("YES\n");
				printf("%d\n",2 );
				printf("%I64d %I64d\n",cy,x );
				printf("%I64d %I64d\n",cx,y );
				return 0;
			}
		}
	}
	printf("NO\n");

	return 0;
}