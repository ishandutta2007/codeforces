#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 10000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n[26];
char str[1000];
int nn;

int main()
{
	cin>>nn;
	RPT(i,0,nn)
	{
		cin>>str;
		n[str[0]-'a']++;
	}
	LL ans=0;
	
	RPT(i,0,26)
	{
		ans+=(n[i]/2)*(n[i]/2-1)/2+(n[i]-n[i]/2)*(n[i]-n[i]/2-1)/2;
	}
	cout<<ans;
	return ~~(0^_^0);
}