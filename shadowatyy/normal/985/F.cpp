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

#define int long long
const int N = 2e5+7;

int n, q, P, MOD;

string s;

int ha[26][N];
int pot[N];

bool isPrime(int x)
{
	for(int i = 2; i*i <= x; ++i)
	{
		if(x%i==0)
			return 0;
	}

	return 1;
}

int get(int l, int a, int b)
{
	return (ha[l][b]-ha[l][a-1]+MOD)*pot[n-b]%MOD;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	srand(time(NULL));

	P = rand()%1000+30;

	while(!isPrime(P))
		++P;

	MOD = rand()%10000+1e9;

	while(!isPrime(MOD))
		++MOD;

	cin >> n >> q >> s;
	s = '#' + s;

	pot[0] = 1;

	for(int i = 1; i <= n; ++i)
	{
		pot[i] = pot[i-1]*P%MOD;

		for(int j = 0; j < 26; ++j)
		{
			if(s[i]-'a'==j)
				ha[j][i] = pot[i];
			
			ha[j][i] += ha[j][i-1];
			ha[j][i] %= MOD;
		}
	}

	while(q--)
	{
		int x, y, len;
		cin >> x >> y >> len;

		VI A, B;

		for(int i = 0; i < 26; ++i)
		{
			A.pb(get(i, x, x+len-1));
			B.pb(get(i, y, y+len-1));
		}

		sort(ALL(A));
		sort(ALL(B));

		if(A==B)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}