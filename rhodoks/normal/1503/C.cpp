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

typedef pair<int,int> pii;

vector<int> v;
int a[MAXN],c[MAXN];
int n;

bool cmp(int x,int y)
{
	return a[x]<a[y];
}

void init()
{

}

multiset<int> st;
void work()
{
	LL ans=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&c[i]);
		ans+=c[i];
		v.push_back(i);
	}
	//ans+=c[1];
	sort(v.begin(),v.end(),cmp);
	
	int ptr=0;
	for (;ptr!=1;ptr++);
		//st.insert(a[v[ptr]]+c[v[ptr]]);
	//int cur=ptr;
	int maxv=a[v[0]]+c[v[0]];
	for (int i=1;i<n;i++)
	{
		//WRT(maxv)
	//	WRT(a[v[i]])
		if (a[v[i]]>maxv)
			ans+=-maxv+a[v[i]];
		maxv=max(maxv,a[v[i]]+c[v[i]]);
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