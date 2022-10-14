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
int p[MAXN];
vector<int> v;
int l[MAXN],r[MAXN];
multiset<int,greater<int> > st;
int ans=0;
void init()
{

}

void work()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for (int i=1;i<=n;i++)
	{
		if (p[i]>p[i-1] && p[i]>p[i+1])
		{
			if (i!=1)
			for (int j=i-1;;j--)
			{
				if (j==0 || p[j]>p[j+1])
				{
					st.insert(i-j);
					l[i]=i-j;
					break;
				}
			}
			
			if (i!=n)
			for (int j=i+1;;j++)
			{
				if (j==n+1 || p[j]>p[j-1])
				{
					st.insert(j-i);
					r[i]=j-i;
					break;
				}
			}
			//cout<<l[i]<<' '<<r[i]<<endl;
		}
	}
	MRK();
	for (int i=1;i<=n;i++)
		if (i!=1 && i!=n && p[i]>p[i-1] && p[i]>p[i+1])
		{
			//WRT(i);
			st.erase(st.find(l[i]));
			st.erase(st.find(r[i]));
			WRT(i);
			if (st.size()!=0 && max(r[i],l[i])<=*st.begin())
			{
				st.insert(l[i]);
				st.insert(r[i]);
				continue;
			}
			///WRT(i);
			st.insert(l[i]);
			st.insert(r[i]);
			//cout<<l[i]<<' '<<r[i]<<endl;
			if (r[i]/2*2>=l[i] || l[i]/2*2>=r[i])
				continue;
			ans++;
		}
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