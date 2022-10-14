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
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

typedef pair<int,int> pii;
int n;
int a[MAXN],b[MAXN],nxt[MAXN];
void init()
{

}

void work()
{
	scanf("%d",&n);
	vector<int> visit;
	visit.resize(n+1);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		nxt[a[i]]=b[i];
	}
	int cnt=0;
	for (int i=1;i<=n;i++)
		if (visit[i]==0)
		{
			int pos=i;
			while (visit[pos]==0)
			{
				visit[pos]=1;
				pos=nxt[pos];
			}
			cnt++;
		}
	LL ans=1;
	while (cnt--)
	{
		ans=ans+ans;
		if (ans>=MOD)
			ans-=MOD;
	}
	printf("%lld\n",ans%MOD);
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