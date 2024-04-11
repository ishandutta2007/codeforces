#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL u,v;
int cnt[300];
LL ans[1000];
int main()
{
	cin>>u>>v;
	if (u>v || (u&1)!=(v&1))
	{
		cout<<-1;
		return 0;
	}
	for (int i=0;i<63;i++)
	{
		//WRT(1ll<<i);
		if ((u & (1ll<<i)) && (v & (1ll<<i)))
			cnt[i]+=1;
		if (!(u & (1ll<<i)) && (v & (1ll<<i)))
			cnt[i-1]+=2;
		if ((u & (1ll<<i)) && !(v & (1ll<<i)))
		{
			cnt[i]++;
			cnt[i-1]+=2;
			v-=(1ll<<(i+1));
			if (v<0)
			{
				cout<<-1;
				return 0;
			}
		}
	}
	for (int i=0;i<63;i++)
		for (int j=0;j<cnt[i];j++)
			ans[j]|=(1ll<<i);
	int c=0;
	for (int i=0;i<10;i++)
		if (ans[i])
			c++;
	cout<<c<<endl;
	for (int i=0;i<10;i++)
		if (ans[i])
			cout<<ans[i]<<' ';
	return ~~(0^_^0);
}