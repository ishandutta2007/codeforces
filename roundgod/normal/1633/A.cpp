#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n%7==0) {printf("%d\n",n); continue;}
		for(int i=0;i<10;i++)
		{
			if((n-n%10+i)%7==0)
			{
				printf("%d\n",(n-n%10+i));
				break;
			}
		}
	}
	return 0;
}