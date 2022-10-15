#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n%3==1)
		{
			printf("1");
			for(int i=0;i<n/3;i++) printf("21");
		}
		else if(n%3==0)
		{
			for(int i=0;i<n/3;i++) printf("21");
		}
		else
		{
			printf("2");
			for(int i=0;i<n/3;i++) printf("12");
		}
		printf("\n");
	}
	return 0;
}