#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
set<P> s;
int n,q,ans;
int main()
{
	scanf("%d%d",&n,&q);
	ans=n;
	for(int i=0;i<q;i++)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		auto f=s.lower_bound(P(l,-INF));
		while(f!=s.end())
		{
			int R=(*f).F,L=(*f).S;
			int len=min(r,R)-max(l,L)+1;
			if(len<=0) break;
			ans+=len;
			s.erase(f++);
			if(L<l) s.insert(P(l-1,L));
			if(r<R) s.insert(P(R,r+1));
		}
		if(k==1) {s.insert(P(r,l)); ans-=r-l+1;}
		printf("%d\n",ans);
	}
	return 0;
}