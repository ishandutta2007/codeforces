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

int s[MAXN];
int n;
int nxt[MAXN];
LL ans=0;
set<int> st;
void init()
{

}

void update(int i)
{
	if (s[i]>1)
		return;
	st.erase(i);
}

void jump(int i)
{
	if (i>n)
		return;
	int t=i+s[i];
	if (s[i]>1)
	{
		s[i]--;
		update(i);
	}
	int p=*st.lower_bound(t);
	jump(p);
}


void work()
{
	ans=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>s[i];
		//s[i]=n-i+1;
		if (s[i]>1)
			st.insert(i);
		//cout<<s[i]<<' ';
	}
	st.insert(INF);
	for (int i=1;i<n;i++)
	{
		if (i+s[i]>n)
		{
			ans+=s[i]-(n-i);
			s[i]=n-i;
			update(i);
		}
		while (s[i]>1)
		{
			jump(i);
			ans++;
		}
	}
	ans+=s[n]-1;
	cout<<ans<<endl;
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