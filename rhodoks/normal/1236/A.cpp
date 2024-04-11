#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int t,a,b,c,ans;
 
int main()
{
	cin>>t;
	while (t--)
	{
		cin>>a>>b>>c;
		ans=0;
		ans+=3*min(c/2,b);
		b-=min(c/2,b);
		ans+=3*min(a,b/2);
		cout<<ans<<endl;
	}
	return ~~(0^_^0);
}