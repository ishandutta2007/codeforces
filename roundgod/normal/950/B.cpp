#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int a[MAXN],b[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<m;i++)
		scanf("%d",&b[i]);
	int cnt=0,t1=0,t2=0,sum1=a[0],sum2=b[0];
	while(t1<n&&t2<m)
	{
		if(sum1==sum2)
		{
			cnt++;
			sum1=sum2=0;
			t1++;
			t2++;
			if(t1<n&&t2<m) {sum1=a[t1]; sum2=b[t2];}
			continue;
		}
		else if(sum1<sum2)
		{
			t1++;
			sum1+=a[t1];
		}
		else
		{
			t2++;
			sum2+=b[t2];
		}
	}
	printf("%d\n",cnt);
	return 0;
}