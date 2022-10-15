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
		int lasto=0,laste=0;
		bool f=true;
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&a[i]);
			if(a[i]&1) {if(lasto>a[i]) f=false; lasto=a[i];}
			else {if(laste>a[i]) f=false; laste=a[i];}
		}
		if(f) puts("Yes"); else puts("No");
	}
	return 0;
}