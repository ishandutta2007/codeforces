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
int a[MAXN];
void print()
{
	for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int now=n;
		for(int i=1;i<=n;i++)
		{
			if(i==n)
			{
				a[i]=now;
				print();
				break;
			}
			a[i+1]=now;
			a[i]=now-1;
			for(int j=i+2;j<=n;j++) a[j]=n-j+1;
			print();
			a[i]=now;
			now--;
		}
	}
	return 0;
}