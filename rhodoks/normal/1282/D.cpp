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

int na,nb;
int cnt[310];
int in;
void q()
{
	for (int i=0;i<na;i++)
	{
		for (int j=0;j<cnt[i];j++)
			cout<<'b';
		cout<<'a';
	}
		printf("\n");
	
	fflush(stdout);
	cin>>in;
}
int main()
{
	for (int i=0;i<300;i++)
		cout<<'a';
		printf("\n");
	fflush(stdout);
	cin>>na;
	for (int i=0;i<300;i++)
		cout<<'b';
		printf("\n");
	fflush(stdout);
	cin>>nb;
	na=300-na;
	nb=300-nb;
	if (nb==0)
	{
	for (int i=0;i<na;i++)
		cout<<'a';
	fflush(stdout);
	return 0;
		
	}
	if (na==0)
	{
	for (int i=0;i<nb;i++)
		cout<<'b';
	fflush(stdout);
	return 0;
		
	}
	int tot=0;
	int lst=nb;
	for (int i=0;i<na;i++)
	{
		while (1)
		{
			cnt[i]++;
			q();
			if (in==0)
			{
				tot++;
				return 0;
			}
			if (in<lst)
			{
				lst=in;
				tot++;
			}
			else
			{
				cnt[i]--;
				break;
			}
		}
	}
	
	for (int i=0;i<na;i++)
	{
		for (int j=0;j<cnt[i];j++)
			cout<<'b';
		cout<<'a';
	}
		for (int j=0;j<nb-tot;j++)
			cout<<'b';
	//printf("\n");
	fflush(stdout);
	return ~~(0^_^0);
}