#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 510
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int a[MAXN];
int tmp[MAXN];
int dp[MAXN][MAXN];
stack<int> stk; 
int n;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
		{
			while (!stk.empty())
				stk.pop();
			for (int k=i;k<=j;k++)
			{
				int pos=a[k];
				while (!stk.empty() && stk.top()==pos)
				{
					stk.pop();
					pos++;
				}
				stk.push(pos);
			}
			dp[i][j]=stk.size();
			//cout<<i<<' '<<j<<' '<<ans[i][j]<<endl;
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			for (int k=i;k<j;k++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
		}
	cout<<dp[1][n];
	return ~~(0^_^0);
}