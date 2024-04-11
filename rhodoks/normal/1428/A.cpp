#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int xa,xb,ya,yb;
void work()
{
	cin>>xa>>ya>>xb>>yb;
	int ans;
	if (xa==xb || ya==yb)
	{
		ans=abs(xa-xb)+abs(ya-yb);
	}
	else
	{
		ans=abs(xa-xb)+abs(ya-yb)+2;
	}
	printf("%d\n",ans);
}

int main()
{
	int t;
	cin>>t;
	while (t--)
		work(); 
	return ~~(0^_^0);
}