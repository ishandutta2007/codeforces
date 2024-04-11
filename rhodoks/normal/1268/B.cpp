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
 
int n;
vector<int> v;
LL ans1,ans2;
 
int main()
{
	int x;
	cin>>n;
	int lst=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		ans1+=x/2;
		ans2+=x/2;
		if (x&1)
			(i&1) ? ans1++:ans2++;
	}
	cout<<min(ans1,ans2);
	return ~~(0^_^0);
}