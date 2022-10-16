#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>

using namespace std;
int q,m;
long long n,k,N;
int main()
{
	scanf("%lld%d",&N,&q);
	while(q--)
	{
		scanf("%lld",&k);
//		for(long long t=1;t<=N;t++)
		{
			n=N;
			long long t=k;
//			k=t;
			k--;
			long long tmp=0,lvl=1,curtype=0,ans=1;
			while(1)
			{
//				cout<<n<<' '<<k<<' '<<tmp<<' '<<lvl<<' '<<curtype<<' '<<tmp+curtype*lvl<<endl;
				if((t-1)%(2*lvl)==tmp+curtype*lvl)
				{
					printf("%lld\n",ans+k/2);
					break;
				}
				else
				{
					long long w=n;
					tmp+=(curtype^1)*lvl;
					k-=(k+(curtype^1))/2;
					ans+=(n+(curtype^1))/2;
					n-=(n+(curtype^1))/2;
					curtype^=w%2;
					lvl*=2;
				}
			}
		}
	}
	return 0;
}