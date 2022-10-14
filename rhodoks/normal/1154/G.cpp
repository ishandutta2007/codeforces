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
#define WRT(x) cout<<#x<<" = "<<x<<endl;

#define MAXA 10001000
#define MAXM 10000
#define MAXN 1001000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL buc[MAXA<<1];
LL n;
LL a[MAXA<<1][2];
int mp[MAXA][2];
void init()
{
	int x;
	cin>>n;
	RPT(i,1,n+1)
	{
		scanf("%d",&x);
		if (mp[x][0]==0)
			mp[x][0]=i;
		else if (mp[x][1]==0)
			mp[x][1]=i;
		buc[x]++;
	}
}

void process()
{
	RPT(i,1,MAXA)
	{
		a[i][0]=-1;
		for (int num=2,j=i;j<MAXA;j+=i)
		{
			if (num<=0)
				break;
			if (num>=1 && buc[j]>=2)
			{
				num--;
				a[i][num]=j/i;
			}
			if (num>=1 && buc[j]>=1)
			{
				num--;
				a[i][num]=j/i;
			}
		}
	}
}

void work()
{
	LL ans=LLINF;
	LL s1,s2;
	RPT(i,1,MAXA)
	{
		if (a[i][0]==-1)
			continue;
		if (ans>(LL)i*(LL)a[i][0]*(LL)a[i][1])
		{
			ans=(LL)i*(LL)a[i][0]*(LL)a[i][1];
			s1=(LL)i*(LL)a[i][0];
			s2=(LL)i*(LL)a[i][1];
		}
	}
	int x1=mp[s1][0],x2;
	if (s2==s1)
		x2=mp[s2][1];
	else
		x2=mp[s2][0];
	if (x1>x2)
		swap(x1,x2);
	cout<<x1<<' '<<x2;
}

int main()
{
	init();
	process();
	work();
	return ~~(0^_^0);
}