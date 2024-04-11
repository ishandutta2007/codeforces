#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int s,f;
	scanf("%d%d",&s,&f);
	int num=f-s;
	int sum=0,ans=0,t=1;
	for(int i=0;i<num;i++)
		sum+=a[i];
	ans=sum;
	timezone=s;
	for(int i=num;i%n!=num-1;i++)
	{
		sum+=a[i%n];
		sum-=a[(i-num)%n];
		timezone--;
		if(timezone==0) timezone=n;
		if(sum>ans)
		{
			ans=sum;
			t=timezone;
		}
		else if(sum==ans)
		{
			if(t>timezone) t=timezone;
		}
	}
	printf("%d\n",t);
	return 0;
}