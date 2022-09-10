#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

const int N = 357;

int n, len;

string s[N];

int poprz[26];
int nast[26];
int wyst[26];
int juz[26];

string res;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	if(n>351)
	{
		cout << "NO";
		return 0;
	}

	for(int i = 0; i < 26; ++i)
	{
		nast[i] = -1;
		poprz[i] = -1;
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> s[i];

		if(s[i].size()>26)
		{
			cout << "NO";
			return 0;
		}

		for(int j = 0; j < s[i].size(); ++j)
		{
			for(int k = j+1; k < s[i].size(); ++k)
			{
				if(s[i][j]==s[i][k])
				{
					cout << "NO";
					return 0;
				}
			}
		}

		for(int j = 0; j+1 < s[i].size(); ++j)
		{
			if(poprz[s[i][j+1]-'a']!=-1 && poprz[s[i][j+1]-'a']!=s[i][j]-'a')
			{
				cout << "NO";
				return 0;
			}

			poprz[s[i][j+1]-'a'] = s[i][j]-'a';
			
			if(nast[s[i][j]-'a']!=-1 && nast[s[i][j]-'a']!=s[i][j+1]-'a')
			{
				cout << "NO";
				return 0;
			}

			nast[s[i][j]-'a'] = s[i][j+1]-'a';
		}

		for(auto it:s[i])
		{
			wyst[it-'a'] = 1;
		}
	}

	for(int i = 0; i < 26; ++i)
	{
		if(wyst[i])
			++len;
	}

	int curr = inf;

	for(int i = 0; i < len; ++i)
	{
		if(curr==inf)
		{
			for(int j = 0; j < 26; ++j)
			{
				if(wyst[j] && !juz[j] && poprz[j]==-1)
					curr = min(curr, j);
			}
		}

		if(curr==inf)
		{
			cout << "NO";
			return 0;
		}

		res += char(curr+'a');
		juz[curr] = 1;

		if(nast[curr]!=-1)
			curr = nast[curr];
		else
			curr = inf;

		if(i==len-1 && curr!=inf)
		{
			cout << "NO";
			return 0;
		}
	}

	cout << res;
}