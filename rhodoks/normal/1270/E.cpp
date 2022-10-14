#include <bits/stdc++.h>
#define DB double
#define LL long long

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

int x[MAXN],y[MAXN];
int n;
int cnt[2][2];
vector<int> v;

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	while (1)
	{
		MST(cnt,0);
		for (int i=1;i<=n;i++)
			cnt[x[i]&1][y[i]&1]++;
		int c=0;
		for (int i=0;i<2;i++)
			for (int j=0;j<2;j++)
				if (cnt[i][j])
					c++;
		if (c>=2)
		{
			if ((cnt[0][0] && cnt[1][1] && !(cnt[0][1]+cnt[1][0])) || (cnt[0][1] && cnt[1][0] && !(cnt[0][0]+cnt[1][1])))
			{
				for (int i=1;i<=n;i++)
					if (x[i]&1)
						v.push_back(i);
			}
			else
			{
				for (int i=1;i<=n;i++)
					if ((x[i]&1) ^ (y[i]&1))
						v.push_back(i);
			}
			cout<<v.size()<<endl;
			for (auto p:v)
				cout<<p<<' ';
			return 0;
		}
		for (int i=1;i<=n;i++)
		{
			x[i]>>=1;
			y[i]>>=1;
		}
	}
	return ~~(0^_^0);
}