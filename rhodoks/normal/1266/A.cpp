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

int n;
char s[1000];
int cnt[20];

int main()
{
	cin>>n;
	while (n--)
	{
		int sum=0;
		int num=0;
		cin>>s;
		MST(cnt,0);
		int len=strlen(s);
		for (int i=0;i<len;i++)
			cnt[s[i]-'0']++;
		for (int i=0;i<9;i++)
		{
			sum+=i*cnt[i];
			if ((i&1)==0)
				num+=cnt[i];
		}
		//cout<<cnt[0]<<' '<<num<<' '<<sum<<endl;
		if (cnt[0] && num>=2 && sum%3==0)
			cout<<"red"<<endl;
		else
			cout<<"cyan"<<endl;
	}
	return ~~(0^_^0);
}