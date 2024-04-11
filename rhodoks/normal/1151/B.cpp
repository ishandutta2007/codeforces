#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=x;i<y;i++)
#define DRPT(i,x,y) for (REG int i=x;i>y;i--)
#define MST(a,b) memset(a,b,sizeof(a))
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

int a[510][510];
int n,m;
int lst[510][1200];
int cnt[510];

int main()
{
	bool flag=true;
	cin>>n>>m;
	RPT(i,1,n+1)
	{
		RPT(j,1,m+1)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int pos[510][2];
	RPT(i,0,10)
	{
		int tem=0;
		bool flag=false;
		int record;
		MST(pos,0);
		RPT(j,1,n+1)
		{
			RPT(k,1,m+1)
			{
				int x=(1<<i) & (a[j][k]);
				if (x>0)
					x=1;
				else
					x=0;
				if (pos[j][x]==0)
					pos[j][x]=k;
			}
			if (pos[j][1] && pos[j][0])
			{
				if (flag) 
					tem++;
				else
				{
					flag=true;
					record=j;
				}
			}
			else
				if (pos[j][1] && !pos[j][0])
					tem++;
		}
		if (tem%2==1 && !flag)
		{
			cout<<"TAK"<<endl;
			RPT(j,1,n+1)
			{
				if (pos[j][1])
					cout<<pos[j][1];
				else
					cout<<pos[j][0];
				cout<<' ';
			}
			return 0;
		}
		if (flag)
		{
			cout<<"TAK"<<endl;
			RPT(j,1,n+1)
			{
				if (j==record)
				{
					cout<<pos[j][(tem%2)^1]<<' ';
					continue;
				}
				if (pos[j][1])
					cout<<pos[j][1];
				else
					cout<<pos[j][0];
				cout<<' ';
			}
			return 0;
		}
	}
	cout<<"NIE";

	return ~~(0^_^0);
}