#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000007
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

char t[7][7];

bool diag1(int i, int j)
{
	int c = 0;

	if(t[i][j]=='o')
		return 0;

	if(t[i-1][j+1]=='o')
		return 0;

	if(t[i-2][j+2]=='o')
		return 0;

	if(t[i][j]=='x')
		++c;

	if(t[i-1][j+1]=='x')
		++c;

	if(t[i-2][j+2]=='x')
		++c;

	if(c==2)
		return 1;

	return 0;
		
}

bool diag2(int i, int j)
{
	int c = 0;

	if(t[i][j]=='o')
		return 0;

	if(t[i-1][j-1]=='o')
		return 0;

	if(t[i-2][j-2]=='o')
		return 0;

	if(t[i][j]=='x')
		++c;

	if(t[i-1][j-1]=='x')
		++c;

	if(t[i-2][j-2]=='x')
		++c;

	if(c==2)
		return 1;

	return 0;
		
}

bool col(int i, int j)
{
	int c = 0;

	if(t[i][j]=='o')
		return 0;

	if(t[i-1][j]=='o')
		return 0;

	if(t[i-2][j]=='o')
		return 0;

	if(t[i][j]=='x')
		++c;

	if(t[i-1][j]=='x')
		++c;

	if(t[i-2][j]=='x')
		++c;

	if(c==2)
		return 1;

	return 0;
}

bool row(int i, int j)
{
	int c = 0;

	if(t[i][j]=='o')
		return 0;

	if(t[i][j+1]=='o')
		return 0;

	if(t[i][j+2]=='o')
		return 0;

	if(t[i][j]=='x')
		++c;

	if(t[i][j+1]=='x')
		++c;

	if(t[i][j+2]=='x')
		++c;

	if(c==2)
		return 1;

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	for(int i = 1; i <= 4; ++i)
	{
		for(int j = 1; j <= 4; ++j)
		{
			cin >> t[i][j];
		}
	}

	for(int i = 3; i <= 4; ++i)
	{
		for(int j = 1; j <= 2; ++j)
		{
			if(diag1(i, j))
			{
				cout << "YES";
				return 0;
			}
		}
	}

	for(int i = 3; i <= 4; ++i)
	{
		for(int j = 3; j <= 4; ++j)
		{
			if(diag2(i, j))
			{
				cout << "YES";
				return 0;
			}
		}
	}

	for(int i = 3; i <= 4; ++i)
	{
		for(int j = 1; j <= 4; ++j)
		{
			if(col(i, j))
			{
				cout << "YES";
				return 0;
			}
		}
	}

	for(int i = 1; i <= 4; ++i)
	{
		for(int j = 1; j <= 2; ++j)
		{
			if(row(i, j))
			{
				cout << "YES";
				return 0;
			}
		}
	}

	cout << "NO";
}