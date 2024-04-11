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

#define int LL

char s[20][20];
int n;
int tmp1[15][16400][65];
int tmp2[15][16400][65];
int visit[20];
int a[20];
int k;
int fst;
int all;

void dfs(int pos,int msk,int ans)
{
	if (pos==k)
	{
		//cout<<msk<<'-'<<ans<<endl;
		tmp1[fst][msk][ans]++;
	}
	if (pos==n-k)
	{
		//cout<<msk<<'?'<<ans<<endl;
		tmp2[visit[pos-1]][msk][ans]++;
		return;
	}
	for (int i=0;i<n;i++)
	{
		if (msk & (1<<i))
			continue;
		visit[pos]=i;
		dfs(pos+1,msk | (1<<i),(ans<<1)|s[i][visit[pos-1]]);
	}
}



int cnt[20000];

signed main()
{
	cin>>n;
	all=(1<<n)-1;
	k=n/2;
	int allk=(1<<(k-1));
	int allkk=(1<<(n-k-1));
	for (int i=0;i<n;i++)
	{
		cin>>s[i];
		//WRT(s[i]);
	}
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			s[i][j]-='0';
				
	for (fst=0;fst<n;fst++)
	{
		visit[0]=fst;
		dfs(1,1<<fst,0);
	}
	for (int msk=0;msk<all;msk++)
	{
		int c=0;
		for (int i=0;i<n;i++)
			if (msk & (1<<i))
				c++;
		if (c!=k)
			continue;
		for (int i=0;i<n;i++)
			if (msk & (1<<i))
				for (int j=0;j<n;j++)
				{
					if (msk & (1<<j))
						continue;
					for (int mk=0;mk<allk;mk++)
					{
						//cout<<i<<' '<<msk<<' '<<mk<<' '<<tmp1[i][msk][mk]<<endl;
						if (tmp1[i][msk][mk]==0)
							continue;
						for (int mkk=0;mkk<allkk;mkk++)
						{
							//cout<<msk<<' '<<mkk<<' '<<tmp2[j][all ^ msk][mkk]<<endl;
							//cout<<(mkk<<(k+1) | s[i][j]<<k | mk)<<' '<<tmp2[j][all ^ msk][mkk]*tmp1[i][msk][mk]<<endl;
							cnt[mkk<<(k) | s[i][j]<<(k-1) | mk]+=tmp2[j][all ^ msk][mkk]*tmp1[i][msk][mk];
						}
					}
				}
	}
	for (int i=0;i<(1<<(n-1));i++)
		printf("%lld ",cnt[i]);
	return ~~(0^_^0);
}