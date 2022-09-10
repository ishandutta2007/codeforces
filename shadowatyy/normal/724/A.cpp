#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000000
#define INF 1000000000000000000LL
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
using namespace std;

string s1, s2;

int l1, l2;

int m[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string d[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s1 >> s2;

	while(d[l1]!=s1)
		++l1;

	while(d[l2]!=s2)
		++l2;

	for(int i = 0; i < 11; ++i)
	{
		if((l1+m[i])%7==l2)
		{
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";
}