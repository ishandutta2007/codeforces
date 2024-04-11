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

int n;
char s[MAXN];
int pos[MAXN];
int cnt=0; 

typedef pair<int,int> pii;
vector<pii> v;
void work()
{
	cin>>n>>(s+1);
	int sum=0;
	LL val=0;
	LL ans=0;
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='1')
			sum++;
		if (s[i]=='0' || i==n)
		{
			if (i==n && s[i]=='1')
				i=n+1;
			for (int j=1;j<=sum;j++)
			{
				val+=i-sum-pos[j]+j-1;
				ans+=val;
				pos[j]=i-j;
			}
			sum=0;
		}
		WRT(val);
		if (s[i]=='0')
			ans+=val;
	}	
	cout<<ans<<endl;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	int casenum=1;
	//scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}