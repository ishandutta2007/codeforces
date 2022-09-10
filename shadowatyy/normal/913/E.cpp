#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

string dp[3][256];

VPII juz;

int neg(int a)
{
	return (~a)&255;
}

struct comp
{
	bool operator()(const pair<PII, PII> &a, const pair<PII, PII> &b)
	{
		int la = dp[a.st.st][a.st.nd].size(), lb = dp[b.st.st][b.st.nd].size();

		if(a.nd!=mp(-1, -1))
			la += dp[a.nd.st][a.nd.nd].size();

		if(b.nd!=mp(-1, -1))
			lb += dp[b.nd.st][b.nd.nd].size();

		if(la==lb)
			return a<b;
		else
			return la<lb;
	}
};

set<pair<PII, PII>, comp> S;

void neguj(int pa, int ma)
{
	string nowy;

	if(pa==0)
		nowy = "!" + dp[pa][ma];
	else 
		nowy = "!(" + dp[pa][ma] + ")";

	if(dp[0][neg(ma)].empty() || dp[0][neg(ma)].size() > nowy.size() || (dp[0][neg(ma)].size() == nowy.size() && dp[0][neg(ma)] > nowy) )
	{	
		dp[0][neg(ma)] = nowy;

		for(auto it:juz)
		{
			S.emplace(it, mp(0, neg(ma)));
			S.emplace(mp(0, neg(ma)), it);
		}

		juz.eb(0, neg(ma));
		S.emplace(mp(0, neg(ma)), mp(-1, -1));
	}
}

void nawiasuj(int pa, int ma)
{
	string nowy = "(" + dp[pa][ma] + ")";

	if(dp[0][ma].empty() || dp[0][ma].size() > nowy.size() || (dp[0][ma].size() == nowy.size() && dp[0][ma] > nowy) )
	{	
		dp[0][ma] = nowy;

		for(auto it:juz)
		{
			S.emplace(it, mp(0, ma));
			S.emplace(mp(0, ma), it);
		}

		juz.eb(0, ma);
		S.emplace(mp(0, ma), mp(-1, -1));
	}
}

void anduj(int pa, int ma, int pb, int mb)
{
	string nowy;

	if(pa<=1)
		nowy += dp[pa][ma];
	else
		nowy += "(" + dp[pa][ma] + ")";

	nowy += "&";

	if(pb<1)
		nowy += dp[pb][mb];
	else
		nowy += "(" + dp[pb][mb] + ")";

	if(dp[1][ma&mb].empty() || dp[1][ma&mb].size() > nowy.size() || (dp[1][ma&mb].size() == nowy.size() && dp[1][ma&mb] > nowy) )
	{
		dp[1][ma&mb] = nowy;

		for(auto it:juz)
		{
			S.emplace(it, mp(1, ma&mb));
			S.emplace(mp(1, ma&mb), it);
		}

		juz.eb(1, ma&mb);
		S.emplace(mp(1, ma&mb), mp(-1, -1));
	}
}

void oruj(int pa, int ma, int pb, int mb)
{
	string nowy;

	if(pa<=2)
		nowy += dp[pa][ma];
	else
		nowy += "(" + dp[pa][ma] + ")";

	nowy += "|";

	if(pb<2)
		nowy += dp[pb][mb];
	else
		nowy += "(" + dp[pb][mb] + ")";

	if(dp[2][ma|mb].empty() || dp[2][ma|mb].size() > nowy.size() || (dp[2][ma|mb].size() == nowy.size() && dp[2][ma|mb] > nowy) )
	{
		dp[2][ma|mb] = nowy;

		for(auto it:juz)
		{
			S.emplace(it, mp(2, ma|mb));
			S.emplace(mp(2, ma|mb), it);
		}

		juz.eb(2, ma|mb);
		S.emplace(mp(2, ma|mb), mp(-1, -1));
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	dp[0][240] = "x";
	dp[0][204] = "y";
	dp[0][170] = "z";

	juz.eb(0, 240);
	juz.eb(0, 204);
	juz.eb(0, 170);

	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			S.emplace(juz[i], juz[j]);
		}

		S.emplace(juz[i], mp(-1, -1));
	}

	while(!S.empty())
	{
		auto v = *S.begin();
		S.erase(S.begin());

		if(v.nd==mp(-1, -1))
		{
			neguj(v.st.st, v.st.nd);
			nawiasuj(v.st.st, v.st.nd);
		}
		else
		{
			oruj(v.st.st, v.st.nd, v.nd.st, v.nd.nd);
			anduj(v.st.st, v.st.nd, v.nd.st, v.nd.nd);
		}
	}

	int n;
	string s;

	cin >> n;

	while(n--)
	{
		cin >> s;

		int q = 0;

		for(int i = 0; i < 8; ++i)
		{
			if(s[i]=='1')
				q |= 1<<i;
		}

		string ans = dp[0][q];

		for(int i = 1; i <= 2; ++i)
		{
			if(ans.size() > dp[i][q].size() || (ans.size() == dp[i][q].size() && ans > dp[i][q]) )
				ans = dp[i][q];
		}

		cout << ans << endl;		
	}
}