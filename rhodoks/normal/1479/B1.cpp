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
int a[MAXN];
void init()
{
 
}
 
int lst; 
int cnt; 
vector<int> v1,v2;
 
void insert()
{
	
}
typedef pair<int,int> pii;
vector<pii> v;
void work()
{
	int midp=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		if (a[i]!=lst )
		{
			if (i>1)
				v.push_back({lst,cnt});
			lst=a[i];
			cnt=1;
		}
		else
		{
			cnt++;
		}
	}
	v.push_back({lst,cnt});
	
	int ans=0;
	for (int i=0;i<v.size();i++)
	{
		//cout<<v[i].first<<' '<<v[i].second<<endl;
		if (v[i].second==1)
			ans++;
		else
		{
			int pos=i;
			while (pos>=2 && v[pos-1].second==1 && v[pos-2].first==v[pos].first)
			{
				if (v[pos-2].second>=2)
				{
					ans--;
					break;
				}
				pos-=2;
			}
			ans+=2;
		}
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