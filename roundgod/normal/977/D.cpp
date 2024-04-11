#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
ll a[MAXN];
set<ll> s;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
		s.insert(a[i]);
	}
	for(int i=0;i<n;i++)
	{
		ll st=a[i];
		bool f=true;
		for(int j=0;j<n-1;j++)
		{
			if(st%3==0&&s.count(st/3)==1)
			{
				st=st/3;
				continue;
			}
			else if(st<=2LL*INF*INF&&s.count(st*2)==1)
			{
				st=st*2;
				continue;
			}
			else {f=false; break;}
		}
		if(f)
		{
			ll st=a[i];
			printf("%I64d ",st);
			for(int j=0;j<n-1;j++)
			{
				if(st%3==0&&s.count(st/3)==1)
				{
					st=st/3;
					printf("%I64d ",st);
				}
				else if(st<=2LL*INF*INF&&s.count(st*2)==1)
				{
					st=st*2;
					printf("%I64d ",st);
				}
			}
			break;
		}
	}
	puts("");
	return 0;
}