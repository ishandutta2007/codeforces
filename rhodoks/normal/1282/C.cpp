#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL n,t,a,b;
typedef pair<LL,LL> pii;
pii p[MAXN];
int main()
{
	int cse;
	cin>>cse;
	while (cse--)
	{
		LL ans=0;
		LL cnta=0,cntb=0;
		cin>>n>>t>>a>>b;
		for (int i=1;i<=n;i++)
		{
			scanf("%lld",&p[i].second);
			if (p[i].second==0)
			{
				p[i].second=a;
				cnta++;
			}
			else
			{
				p[i].second=b;
				cntb++;
			}
		}
		for (int i=1;i<=n;i++)
			scanf("%lld",&p[i].first);
		sort(p+1,p+n+1);
		//for (int i=1;i<=n;i++)
		//	cout<<p[i].first<<' '<<p[i].second<<endl;
		LL tim=0;
		LL cnt=0;
		
			if (1)
			{
				LL rtim=p[1].first-1;
				if (rtim<=(LL)cnta*a)
				{
					ans=max(ans,cnt+rtim/a);
				}
				else
				{
					ans=max(ans,cnt+cnta+min((LL)cntb,(rtim-(LL)cnta*a)/b));
				}
			}
		p[n+1].first=t+1;
		for (int i=1;i<=n;i++)
		{
			tim+=p[i].second;
			//cout<<tim<<' '<<p[i+1].first<<endl;
			if (tim>t)
				break;
			if (p[i].second==a)
				cnta--;
			else
				cntb--;
			cnt++;
			if (tim<p[i+1].first)
			{
				LL rtim=p[i+1].first-1-tim;
				if (rtim<=(LL)cnta*a)
				{
					ans=max(ans,cnt+rtim/a);
				}
				else
				{
					ans=max(ans,cnt+cnta+min((LL)cntb,(rtim-(LL)cnta*a)/b));
				}
				//WRT(ans);
			}
		}
		/*
			if (tim<=t)
			{
				LL rtim=t-tim;
				if (rtim<=(LL)cnta*a)
				{
					ans=max(ans,cnt+rtim/a);
				}
				else
				{
					ans=max(ans,cnt+cnta+min((LL)cntb,(rtim-(LL)cnta*a)/b));
				}
			}
			*/
		//WRT(ans);
		cout<<ans<<endl;
	}
	return ~~(0^_^0);
}