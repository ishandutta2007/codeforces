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

int cnt[260];
char p[120],h[120];
int lp,lh;

bool check()
{
	for (int i='a';i<='z';i++)
		if (cnt[i])
			return false;
	return true;
}
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		MST(cnt,0);
		cin>>p>>h;
		lp=strlen(p);
		lh=strlen(h);
		for (int i=0;i<lp;i++)
			cnt[p[i]]++;
		if (lh<lp)
		{
			cout<<"NO"<<endl;
			continue;
		}	
		int l=0,r=lp-1;
		for (int i=l;i<=r;i++)
			cnt[h[i]]--;
		bool f=false;
		while (1)
		{
			if (check())
			{
				cout<<"YES"<<endl;
				f=1;
				break;
			}
			cnt[h[l++]]++;
			cnt[h[++r]]--;
			if (r>=lh)
				break;
		}
		if (!f)
		{
			cout<<"NO"<<endl;
		}
	}
	return ~~(0^_^0);
}