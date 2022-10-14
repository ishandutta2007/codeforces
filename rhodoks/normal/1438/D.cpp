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
vector<int> v;
int a[MAXN];
int sum=0;

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i],sum^=a[i],v.push_back(a[i]);
	if (n%2==0)
	{
		if (sum)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		v.pop_back();
	}
	cout<<"YES"<<endl;
	cout<<v.size()-1<<endl;
	for (int i=0;i<v.size()-2;i+=2)
	{ 
		cout<<i+1<<' '<<i+2<<' '<<i+3<<endl;
	}
	for (int i=0;i<v.size()-2;i+=2)
	{ 
		cout<<i+1<<' '<<i+2<<' '<<v.size()<<endl;
	}
	return ~~(0^_^0);
}