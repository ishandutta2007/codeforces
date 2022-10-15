#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,c[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&c[i]);
		bool f=true;
		int id=-1;
		for(int i=1;i<=n;i++)
		{
			if(c[i]==1)
			{
				id=i; 
				break;
			}
		}
		if(id==-1) {puts("NO"); continue;}
		int last=1;
		for(int i=1;i<=n-1;i++)
		{
			id++;
			if(id>n) id=1;
			if(c[id]<2||c[id]>last+1) {f=false; break;}
			last=c[id];
		}
		if(f) puts("YES"); else puts("NO");
	}
	return 0;
}