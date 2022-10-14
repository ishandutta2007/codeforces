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

int n;
int a[MAXN];
int b[MAXN];
bool cho[MAXN];

int main()
{
	cin>>n;
	int x;
	int mx=0;
	int pos1=-1;
	bool f=true,ff=true;
	RPT(i,0,n)
	{
		cin>>a[i];
		cho[a[i]]=true;
	}
	RPT(i,0,n)
	{
		cin>>b[i];
		if (b[i]==1)
			pos1=i;
		if (b[i]!=0)
		{
			mx=max(mx,i+2-b[i]);
			//cout<<mx<<' '<<i<<endl;
		}
	}
	if (pos1!=-1)
	{
		RPT(i,pos1,n)
			if (b[i]!=i-pos1+1)
			{
				f=false;
				break;
			}
		if (f==true)
		{
			int r=b[n-1];
			RPT(i,r+1,n+1)
			{
				if (cho[i]==false)
				{
					ff=false;
					break;
				}
				cho[b[i-r-1]]=true;	
			}
			if (ff==true)
			{
				cout<<n-r;
				return 0;
			}
		}
	}
	cout<<mx+n;
	return ~~(0^_^0);
}