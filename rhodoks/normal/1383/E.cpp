#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 2100000
#define MAXM 410000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

string s;
int to[MAXN][2];
int nxt[MAXN][2];
typedef pair<int,int> pii;
LL dp[MAXN];
int main()
{
	cin>>s;
	int lst1=INF;
	nxt[s.size()][1]=nxt[s.size()][0]=INF;
	for (int i=s.size()-1;i>=0;i--)
	{
		nxt[i][s[i]-'0']=i;
		nxt[i][(s[i]-'0')^1]=nxt[i+1][(s[i]-'0')^1];
	}
	int cnt0=0;
	set<pii> st;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]=='0')
			cnt0++;
		to[i][1]=nxt[i+1][1];
		if (s[i]=='1')
			to[i][0]=nxt[i][0];
		else
		{
			if (s[i+1]=='0')
				to[i][0]=i+1;
			else
			{
				to[i][0]=INF;
				while (!st.empty() && cnt0>=st.begin()->first)
				{
					to[st.begin()->second][0]=i-cnt0+st.begin()->first;
					st.erase(st.begin());
				}
				st.insert({cnt0+1,i});
			}
		}
		if (s[i]=='1')
			cnt0=0;
	} 
	//for (int i=0;i<s.size();i++)
	//	cout<<i<<' '<<to[i][0]<<' '<<to[i][1]<<endl;
	LL ans=0;
	LL pos=0;
	while (s[pos]!='1' && pos<s.size())
		pos++;
	if (pos==s.size())
	{
		cout<<s.size();
		return 0;
	}
	//WRT(pos)
	int lst=s.size()-1;
	while (s[lst]!='1')
		lst--;
	//WRT(s.size());
	//WRT(lst)
	//WRT(pos);
	dp[pos]=1;
	for (int i=pos;i<s.size();i++)
	{
		//cout<<'!'<<i<<' '<<dp[i]<<endl;
		dp[i]%=MOD;
		if (s[i]=='1')
			ans+=dp[i];
		if (to[i][0]<s.size())
			dp[to[i][0]]+=dp[i];
		if (to[i][1]<s.size())
			dp[to[i][1]]+=dp[i];
	}
	pos=(pos+1)*(s.size()-lst)%MOD;
	//WRT(pos);
	cout<<pos*ans%MOD;
	return ~~(0^_^0);
}