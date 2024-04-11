#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN][MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]!=1)
			{
				bool f=false;
				for(int s=0;s<n;s++)
					for(int t=0;t<n;t++)
						if(a[i][s]+a[t][j]==a[i][j]) {f=true; break;}
				if(!f) {puts("No"); return 0;}
			}
		}
	}
	puts("Yes");
	return 0;
}