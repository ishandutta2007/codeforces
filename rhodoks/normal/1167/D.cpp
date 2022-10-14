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

#define MAXN 510000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n1,n2;
char str[MAXN];
int col[MAXN];
int len;

int main()
{
	cin>>len;
	cin>>str;
	RPT(i,0,len)
	{
		if (str[i]=='(')
		{
			if (n1>n2)
			{
				col[i]=1;
				n2++;
			}
			else
			{
				col[i]=0;
				n1++;
			}
		}
		else
		{
			if (n1<n2)
			{
				col[i]=1;
				n2--;
			}
			else
			{
				col[i]=0;
				n1--;
			}
			
		}
	}
	RPT(i,0,len)
		cout<<col[i];
	return ~~(0^_^0);
}