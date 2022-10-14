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

int n,m;
LL x;
int lst[MAXN];
int a[MAXN],b[MAXN];
int cnt[MAXN];
void work()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		//WRT(a[i])
		b[i]=a[i];
		while (lst[b[i]])
			b[i]=lst[b[i]];
		WRT(b[i]);
	}
	for (int i=1;i<=n;i++)
	{
		cnt[b[i]]++;
	}
	int ans1=0,ans2=0;
	for (int i=1;i<=n;i++)
	{
		ans1=max(ans1,cnt[b[i]]);
	}
	for (int i=1;i<=n;i++)
	{
		if (cnt[b[i]]%2==0 && b[i]!=1)
		{
			cnt[1]+=cnt[b[i]];
			cnt[b[i]]=0;
		}
	}
	for (int i=1;i<=n;i++)
		ans2=max(ans2,cnt[b[i]]);
	ans2=max(ans2,cnt[1]);
	for (int i=1;i<=n;i++)
		cnt[b[i]]=0;
	cnt[1]=0;
	LL q;
	scanf("%lld",&q);
	while (q--)
	{
		scanf("%lld",&x);
		if (x==0)
			printf("%d\n",ans1);
		else
			printf("%d\n",ans2);
	}
	//printf("%d\n",ans);
}

int main()
{
	
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	for (int i=1;i<MAXN;i++)
	{
		//adj[i].push_back(i);
		for (int j=2;j*j*i<MAXN;j++)
		{
			//adj[j*j*i].push_back(i);
			//adj[i].push_back(j*j*i);
			lst[j*j*i]=i;
		}
	}
	WRT(lst[1000000])
	//for (int i=0;i<100;i++)
	//	cout<<i<<' '<<lst[i]<<endl;
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