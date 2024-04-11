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

#define MAXN 210000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n,k;
char s[MAXN],str[MAXN]; 
int main()
{
	cin>>n>>k;
	cin>>str;
	for (int i=0;i<n;i++)
		s[i]=str[i%k];
	bool cmp=1;
	for (int i=0;i<n;i++)
	{
		if (s[i]>str[i])
		{
			break;
		}
		if (s[i]<str[i])
		{
			cmp=0;
			break;
		} 
	}
	if (cmp)
	{
		cout<<n<<endl;
		cout<<s;
		return 0;
	}
	s[k-1]++;
	for (int i=k-1;i>=0;i--)
	{
		if (s[i]>'9')
		{
			s[i]-=10;
			s[i-1]++;
		}
	}
	cout<<n<<endl;
	for (int i=0;i<n;i++)
		s[i]=s[i%k];
	cout<<s;
		 
	return ~~(0^_^0);
}