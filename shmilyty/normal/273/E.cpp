#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
const int mod=1e9+7;
int d[1000][2]={{1,0},{3,1},{4,2},{5,1},{7,2},{9,0},{13,1},{15,2},{19,0},{27,1},{39,2},{40,0},{57,2},{58,1},{81,2},{85,0},{120,2},{121,1},{174,2},{179,0},{255,2},{260,1},{363,2},{382,0},{537,2},{544,1},{780,2},{805,0},{1146,2},{1169,1},{1632,2},{1718,0},{2415,2},{2447,1},{3507,2},{3622,0},{5154,2},{5260,1},{7341,2},{7730,0},{10866,2},{11011,1},{15780,2},{16298,0},{23190,2},{23669,1},{33033,2},{34784,0},{48894,2},{49549,1},{71007,2},{73340,0},{104352,2},{106510,1},{148647,2},{156527,0},{220020,2},{222970,1},{319530,2},{330029,0},{469581,2},{479294,1},{668910,2},{704371,0},{990087,2},{1003364,1},{1437882,2},{1485130,0},{2113113,2},{2156822,1},{3010092,2},{3169669,0},{4455390,2},{4515137,1},{6470466,2},{6683084,0},{9509007,2},{9705698,1},{13545411,2},{14263510,0},{20049252,2},{20318116,1},{29117094,2},{30073877,0},{42790530,2},{43675640,1},{60954348,2},{64185794,0},{90221631,2},{91431521,1},{131026920,2},{135332446,0},{192557382,2},{196540379,1},{274294563,2},{288836072,0},{405997338,2},{411441844,1},{589621137,2},{608996006,0},{866508216,2},{884431705,1}};
int n,p,ans,cnt[3],f[1001][4];
signed main()
{
	n=read(),p=read();
	for(int i=0;d[i][0]&&d[i][0]<=p;i++)
	{
		int l=d[i][0],r;
		if(!d[i+1][0])
			r=p;
		else
			r=min(p,d[i+1][0]-1);
		(cnt[d[i][1]]+=(2*p-l-r)*(r-l+1)/2)%=mod;
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int l=0;l<3;l++)
			for(int j=0;j<4;j++)
				(f[i][j^l]+=f[i-1][j]*cnt[l]%mod)%=mod;
	for(int i=1;i<4;i++)
		(ans+=f[n][i])%=mod;
	cout<<ans; 
	return 0;
}