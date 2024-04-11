#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))

#ifdef _DEBUG_
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#else
#define MRK() ;
#define WRT(x) ;
#endif

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int cnt[MAXN];
int n,l,r;
int x;
void init()
{

}

void work()
{
	cin>>n>>l>>r;
	for (int i=0;i<=n;i++)
		cnt[i]=0;
	for (int i=0;i<l;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	for (int i=0;i<r;i++)
	{
		scanf("%d",&x);
		cnt[x]--;
	}
	int cntl=0,cntr=0;
	int pl=0,pr=0;
	for (int i=0;i<=n;i++)
	{
		//WRT(cnt[i]);
		if (cnt[i]<0)
		{
			cntl+=(-cnt[i]);
			pl+=(-cnt[i])/2;
		}
		else
		{
			cntr+=(cnt[i]);
			pr+=(cnt[i]/2);
		}
	}
	int ans=min(cntl,cntr);
	WRT(ans);
	if (cntl<cntr)
	{
		swap(cntl,cntr);
		swap(pl,pr);
	}
	cntl-=cntr;
	ans+=cntl;
	if (pl*2>=cntl)
		ans-=cntl/2;
	else
		ans-=pl;
	/*
	if (cntl>cntr)
	{
		ans=cntr;
		int tmp=cntl-cntr;
		if (tmp/2<=pl)
			ans+=tmp/2;
		else
			tmp+=tmp-pl;
	}
	if (cntl<cntr)
	{
		ans=cntl;
		int tmp=-cntl+cntr;
		if (tmp/2<=pr)
			ans+=tmp/2;
		else
			tmp+=tmp-pr;
	}
	*/
	
	printf("%d\n",ans);
	
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	init();
	int casenum=1;
	scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}