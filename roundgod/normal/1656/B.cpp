#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
set<int> s;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		s.clear();
		for(int i=1;i<=n;i++) 
		{
			int x;
			scanf("%d",&x);
			s.insert(x);
		}
		bool f=false;
		for(auto it:s) if(s.count(it+k)) f=true; 
		if(f) puts("YES"); else puts("NO");
	}
	return 0;
}