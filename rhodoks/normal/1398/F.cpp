#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 2100000
#define MAXM 410000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n;
string s;
vector<int> g[MAXN];
int nxt[MAXN];
int dp[2];
set<int> st;
int main()
{
	cin>>n>>s;
	for (int i=n-1;i>=0;i--)
	{
		dp[0]++;
		dp[1]++;
		if (s[i]=='1')
			dp[0]=0;
		if (s[i]=='0')
			dp[1]=0;
		if (s[i]!='?')
			nxt[i]=dp[s[i]-'0'];
		else
			nxt[i]=max(dp[0],dp[1]);
		//WRT(nxt[i]);
		//WRT(dp[0]);
		//WRT(dp[1]);
		g[nxt[i]].push_back(i);
		st.insert(i);
	}
	st.insert(INF);
	for (int i=1;i<=n;i++)
	{
		int pos=0;
		int ans=0;
		while (1)
		{
			pos=*st.lower_bound(pos);
			//WRT(pos);
			if (pos>=n)
				break;
			ans+=nxt[pos]/i;
			pos=pos+nxt[pos]/i*i;
		}
		printf("%d ",ans);
		//MRK();
		for (auto p:g[i])
			st.erase(p);
		//MRK();
	}
	return ~~(0^_^0);
}