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

int h,l;
char m[510][510];
int tem[510][2];
int c[2];
	int sum=0;
int main()
{
	cin>>h>>l;
	c[0]=c[1]=-1;
	RPT(i,0,h)
		RPT(j,0,l)
		{
			cin>>m[i][j];
			if (m[i][j]=='*')
			{
				sum++;
				tem[i][0]++;
				tem[j][1]++;
			}
		}
	RPT(i,0,h)
	{
		if (tem[i][0]>=2)
			if (c[0]==-1)
				c[0]=i;
			else
			{
				cout<<"NO";
				return 0;
			}
	}
	RPT(i,0,l)
	{
		if (tem[i][1]>=2)
			if (c[1]==-1)
				c[1]=i;
			else
			{
				cout<<"NO";
				return 0;
			}
	}
	if (m[c[0]][c[1]]!='*')
	{
		cout<<"NO";
		return 0;
	}
	if (c[0]==0 || c[0]==h-1 || c[1]==0 || c[1]==l-1)
	{
		cout<<"NO";
		return 0;
	}
	if (m[c[0]-1][c[1]]=='.' || m[c[0]+1][c[1]]=='.' || m[c[0]][c[1]+1]=='.' || m[c[0]][c[1]-1]=='.')
	{
		cout<<"NO";
		return 0;
	}
	sum--;
	DRPT(i,c[0]-1,-1)
	{
		if (m[i][c[1]]=='.')
			break;
		sum--;
	}
	RPT(i,c[0]+1,h)
	{
		if (m[i][c[1]]=='.')
			break;
		sum--;
	}
	DRPT(i,c[1]-1,-1)
	{
		if (m[c[0]][i]=='.')
			break;
		sum--;
	}
	RPT(i,c[1]+1,l)
	{
		if (m[c[0]][i]=='.')
			break;
		sum--;
	}
	if (sum!=0)
		cout<<"NO";
	else
		cout<<"YES";
	
	return ~~(0^_^0);
}