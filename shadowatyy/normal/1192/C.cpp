#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
#define VI vector<int>
#define VPII vector<PII>
#define LL long long
#define LD long double
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, b, e) for (int i = (b); i <= (int)(e); i++)
#define FORD(i, b, e) for (int i = (b); i >= (int)(e); i--)
#define ll long long
#define st f
#define nd s
#define pb PB
#define eb emplace_back
#define mp make_pair
#define siz(c) SIZ(c)
const int inf = 1e9 + 7;
const LL INF = 1e18L + 7;

#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type
{int o = 0; p << "{"; for (auto c : y) {if (o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if (p > y) p = y;}
sim, class s> void maxi(n &p, s y) {if (p < y) p = y;}

#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif

#define I(x) #x " = ", (x), " "
#define A(a, i) #a "[" #i " = ", i, "] = ", a[i], " "

const int mod = 998244353;
const int A = 62;

int n, ans;

set<string> S;

vector<char> let;

int ile[A][A][A];
int slow[256][256];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	for(int i = 0; i < 26; ++i)
	{
		let.pb('a'+i);
		let.pb('A'+i);
	}

	for(int i = 0; i < 10; ++i)
	{
		let.pb('0'+i);
	}

	cin >> n;

	while(n--)
	{
		string s;
		cin >> s;
		S.insert(s);
		reverse(ALL(s));
		S.insert(s);
	}

	for(int len = 3; len <= 10; ++len)
	{
		for(int i = 0; i < 256; ++i)
		{
			memset(slow[i], 0, sizeof slow[i]);
		}

		for(int i = 0; i < A; ++i)
		{
			for(int j = 0; j < A; ++j)
			{
				memset(ile[i][j], 0, sizeof ile[i][j]);
			}
		}

		for(auto it:S)
		{
			if(siz(it)==len)
				slow[it[0]][it.back()]++;
		}

		for(int i = 0; i < A; ++i)
		{
			for(int j = i; j < A; ++j)
			{
				for(int k = j; k < A; ++k)
				{
					for(int x = 0; x < A; ++x)
					{
						int letX = let[x];
						ile[i][j][k] += (ll)slow[let[i]][letX]*slow[let[j]][letX]%mod*slow[let[k]][letX]%mod;
						
						if(ile[i][j][k]>=mod)
							ile[i][j][k] -= mod;
					}
				}
			}
		}

		for(int i = 0; i < A; ++i)
		{
			for(int j = 0; j < A; ++j)
			{
				for(int k = 0; k < A; ++k)
				{
					int a = i;
					int b = j;
					int c = k;

					if(c<b)
						swap(c, b);

					if(b<a)
						swap(a, b);

					if(c<b)
						swap(c, b);

					ile[i][j][k] = ile[a][b][c];
				}
			}
		}

		//wszystkie rozne

		for(int i = 0; i < A; ++i)
		{
			for(int j = i+1; j < A; ++j)
			{
				for(int k = j+1; k < A; ++k)
				{
					for(int l = k+1; l < A; ++l)
					{
						ans += (ll)ile[i][j][k]*ile[i][j][l]%mod*ile[i][k][l]%mod*ile[j][k][l]%mod*24%mod;
						
						if(ans>=mod)
							ans -= mod;
					}
				}
			}
		}

		//powtorzenia

		for(int i = 0; i < A; ++i)
		{
			for(int j = 0; j < A; ++j)
			{
				for(int k = 0; k < A; ++k)
				{	
					if(i==j || j==k || k==i)
					{
						for(int l = 0; l < A; ++l)
						{
							ans += (ll)ile[i][j][k]*ile[i][j][l]%mod*ile[i][k][l]%mod*ile[j][k][l]%mod;
							
							if(ans>=mod)
								ans -= mod;
						}
					}
					else
					{	
						int l = i;

						ans += (ll)ile[i][j][k]*ile[i][j][l]%mod*ile[i][k][l]%mod*ile[j][k][l]%mod;
						
						if(ans>=mod)
							ans -= mod;

						l = j;

						ans += (ll)ile[i][j][k]*ile[i][j][l]%mod*ile[i][k][l]%mod*ile[j][k][l]%mod;
							
						if(ans>=mod)
							ans -= mod;

						l = k;

						ans += (ll)ile[i][j][k]*ile[i][j][l]%mod*ile[i][k][l]%mod*ile[j][k][l]%mod;
							
						if(ans>=mod)
							ans -= mod;
					}
				}
			}
		}
	}

	cout << ans << endl;
}