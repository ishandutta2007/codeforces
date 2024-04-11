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

#define MAXN 10000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL n;

int main()
{
	queue<int> q;
	int cnt=0;
	int maxbit=-1;
	cin>>n;
	RPT(i,0,31)
	{
		if (n+1 == (1<<i))
		{
			cout<<0;
			return 0;
		}
	}
	DRPT(i,31,-1)
		if ((1<<i) & n)
		{
			maxbit=i;
			break;
		}
	//WRT(maxbit);
	RPT(i,0,40)
	{
		int p;
		for (p=0;p<=maxbit;p++)
			if ((1<<p) & n)
				break;
		n^=(1<<p)-1;
		q.push(p);
		cnt++;
		if ((n+1) == (1<<(maxbit+1)))
			break;
		//WRT(p);
	//	WRT(n);
		n++;
		cnt++;
	}
	cout<<cnt<<endl;
	RPT(i,0,(cnt+1)/2)
	{
		cout<<q.front()<<' ';
		q.pop();
	}
	return ~~(0^_^0);
}