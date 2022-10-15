#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,m,a[MAXN],b[MAXM],type[MAXN],l[MAXN],r[MAXN];
int main()
{
	scanf("%d%d%d",&n,&q,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<q;i++)
		scanf("%d%d%d",&type[i],&l[i],&r[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	for(int i=q-1;i>=0;i--)
	{
		if(type[i]==1)
		{
			for(int j=1;j<=m;j++)
			{
				if(b[j]<l[i]||b[j]>r[i]) continue;
				if(b[j]==l[i]) b[j]=r[i]; else b[j]--;
			}
		}
		else
		{
			for(int j=1;j<=m;j++)
			{
				if(b[j]<l[i]||b[j]>r[i]) continue;
				b[j]=l[i]+r[i]-b[j];
			}
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d ",a[b[i]]);
	return 0;
}