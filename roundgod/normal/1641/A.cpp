#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,x;
multiset<int> s;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&x);
		s.clear();
		for(int i=1;i<=n;i++)
		{
			int y;
			scanf("%d",&y);
			s.insert(y);
		}
		int ans=0;
		while(s.size())
		{
			auto it=s.begin();
			int val=*it;
			if(1LL*val*x<=INF&&s.count(val*x))
			{
				s.erase(s.find(val));
				s.erase(s.find(val*x));
			}
			else {ans++; s.erase(s.find(val));}
		}
		printf("%d\n",ans);
	}
	return 0;
}