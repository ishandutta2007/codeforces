#include <iostream>
using namespace std;
int dp[55][101][1005];
const int qwq=502,qaq=50;
int main(int argc, char** argv) {
	string s;
	cin >> s;
	s="00"+s;
	int n=s.size();
	s=' '+s;
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=qaq+qaq;j++)
			for(int k=0;k<=qwq+qwq;k++)
				dp[i][j][k]=1e9;
	dp[0][qaq][qwq]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=qaq+qaq;j++)
		{
			int need=j*10-qaq*10+s[i+1]-'0';
			for(int k=0;k<=qwq+qwq;k++)
			{
				int now=k-qwq;
		/*		if(i==0&&j==qaq&&k==qwq)
				{
					cout << need << " " << now << '\n';
				}*/
				for(int l=need-now-qaq;l<=need-now+qaq;l++)
				{
					int nxtk=k+l,nxtj=need-(now+l)+qaq,w=max(l,-l)*(n-i);
/*				if(i==0&&j==qaq&&k==qwq)
				{
					cout << l << " " << nxtk-qwq << " "<< nxtj-qaq << " " << w << " "<< dp[i][j][k] << "\n";
				}*/
					if(nxtk>=0&&nxtk<=qwq+qwq&&nxtj>=0&&nxtj<=qaq+qaq)
						dp[i+1][nxtj][nxtk]=min(dp[i+1][nxtj][nxtk],dp[i][j][k]+w);
				}
			}
		}
	}
	int ans=1e9;
	for(int k=0;k<=qwq+qwq;k++)
		ans=min(ans,dp[n][qaq][k]);
	cout << ans;
	return 0;
}