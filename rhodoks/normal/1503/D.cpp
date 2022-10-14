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

void init()
{

}

int a[MAXN],b[MAXN],flip[MAXN],f[MAXN];
int premin[MAXN],sufmax[MAXN];
int n;

int calc(int l,int r)
{
	int ans1,ans2,s1,s2;
	ans1=ans2=0;
	s1=s2=INF;
	for (int i=l;i<=r;i++) 
	{
		WRT(i)
		WRT(flip[i])
		if (f[i]<s1)
		{
			s1=f[i];
			ans1+=flip[i];
		}
		else if (f[i]<s2)
		{
			s2=f[i];
			ans2+=flip[i]^1;
		}
		else
			return -INF;
	}
	//cout<<l<<' '<<r<<' '<<ans1<<' '<<ans2<<endl;
	return min(ans1+ans2,r-l+1-ans1-ans2);
}

void work()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		if (a[i]<=n && b[i]<=n)
		{
			cout<<-1<<endl;
			return;
		}
		if (a[i]>n)
		{
			WRT(i)
			WRT(flip[i])
			swap(a[i],b[i]);
			flip[a[i]]=1;
		}
		f[a[i]]=b[i];
	}
	premin[0]=INF;
	for (int i=1;i<=n;i++)
		premin[i]=min(premin[i-1],f[i]);
	for (int i=n;i>=1;i--)
		sufmax[i]=max(sufmax[i+1],f[i]);
	int lst=1;
	LL ans=0;
	for (int i=1;i<=n;i++)
	{
		if (premin[i]>sufmax[i+1] || lst<=n && i==n)
		{
			ans+=calc(lst,i);
			lst=i+1;
		}
	}
	if (ans<0)
		ans=-1;
	cout<<ans<<endl;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	init();
	int casenum=1;
	//scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}