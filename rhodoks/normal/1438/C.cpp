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
int a[110][110];

void work()
{
	set<int> st;
	cin>>n>>m;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{
			cin>>a[i][j];
			st.insert(-a[i][j]);
		}
	int c=0;
	for (auto p:st)
	{
		p=-p;
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				if (a[i][j]==p)
					a[i][j]+=c^((i+j)&1);
		c^=1;
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
			cout<<a[i][j]<<' ';
		cout<<endl;
	}
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	int t;
	cin>>t;
	while (t--)
		work();
	return ~~(0^_^0);
}