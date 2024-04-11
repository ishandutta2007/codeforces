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

int dp[211][211][810];
LL lst[211][211][810];
char c[211][211][810];
int main()
{
	string s,t;
	cin>>s>>t;
	MST(dp,INF);
	dp[0][0][401]=0;
	for (int i=0;i<=s.size();i++)
		for (int j=0;j<=t.size();j++)
		{
			//cout<<i<<' '<<j<<endl;
			for (int k=1;k<=802;k++)
			{
				if (dp[i+(s[i]=='(')][j+(t[j]=='(')][k+1]>dp[i][j][k]+1)
				{
					//cout<<'('<<' '<<i<<' '<<j<<' '<<k<<endl;
					dp[i+(s[i]=='(')][j+(t[j]=='(')][k+1]=dp[i][j][k]+1;
					lst[i+(s[i]=='(')][j+(t[j]=='(')][k+1]=(((LL)i<<24) | ((LL)j<<12) | k);
					c[i+(s[i]=='(')][j+(t[j]=='(')][k+1]='(';
				}
			}
			for (int k=802;k>401;k--)
				if (dp[i+(s[i]==')')][j+(t[j]==')')][k-1]>dp[i][j][k]+1)
				{
					//cout<<')'<<' '<<i<<' '<<j<<' '<<k<<' '<<(i+s[i]==')')<<' '<<(j+t[j]==')')<<' '<<k-1<<endl;
					dp[i+(s[i]==')')][j+(t[j]==')')][k-1]=dp[i][j][k]+1;
					lst[i+(s[i]==')')][j+(t[j]==')')][k-1]=(((LL)i<<24) | ((LL)j<<12) | k);
					c[i+(s[i]==')')][j+(t[j]==')')][k-1]=')';
				}
		}
	//WRT(s.size());
	//WRT(t.size());
	int ps=s.size();
	int pt=t.size();
	int pk=401;
	stack<char> stk;
	//WRT(dp[s.size()][t.size()][401]);
	while (ps!=0 || pt!=0 || pk!=401)
	{
		stk.push(c[ps][pt][pk]);
		LL t=lst[ps][pt][pk];
		ps=(t>>24);
		pt=((t & 0xfff000)>>12);
		pk=(t & 0xfff);
		//cout<<ps<<' '<<pt<<' '<<pk<<endl;
		//return 0;
	}
	while (!stk.empty())
	{
		cout<<stk.top();
		stk.pop();
	}
	return ~~(0^_^0);
}