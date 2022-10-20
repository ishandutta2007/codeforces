// Dumbest problem ever -- TL 72 with a correct solution
// Submitting this to get AC, because in my opinion the problem is solved






#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
int n;
int a[200005];
int ret[200005],cnt[200005];
P lb[200005],ub[200005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(a[1]>1) return puts("-1");
	lb[1]=ub[1]=mp(1,1);
	for(int i=2;i<=n;i++)
	{
		lb[i]=lb[i-1];
		lb[i].s++;
		ub[i]=ub[i-1];
		ub[i].s++;
		if(lb[i].s>5)
		{
			lb[i].f++;
			lb[i].s=1;
		}
		if(ub[i].s>2)
		{
			ub[i].f++;
			ub[i].s=1;
		}
		if(a[i])
		{
			if(!(lb[i].f<=a[i] && a[i]<=ub[i].f))
			{
				return puts("-1");
			}
			lb[i]=max(lb[i],mp(a[i],1));
			ub[i]=min(ub[i],mp(a[i],INF));
		}
		
	}
	P ans=ub[n];
	if(ans.s==1)
	{
		ans.f--;
		ans.s=INF;
	}
	if(ans<lb[n]) return puts("-1");
	ret[n]=ans.f;
	cnt[ans.f]=1; printf("%d\n",ans.f);
	for(int i=n-1;i>=1;i--)
	{
		ret[i]=min(ret[i+1],ub[i].f);
		if(cnt[ret[i]]==5)
		{
			ret[i]--;
		}
		cnt[ret[i]]++;
	}
	for(int i=1;i<=n;i++) printf("%d%c",ret[i],i==n?'\n':' ');
}