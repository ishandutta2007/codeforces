#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000007
#define INF 1000000000000000007LL
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
using namespace std;

queue<int> R;
queue<int> D;

int n;

string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> s;

	for(int i = 0; i < n; ++i)
	{
		if(s[i]=='R')
			R.push(i);
		else
			D.push(i);
	}

	while(!R.empty() && !D.empty())
	{
		if(R.front()<D.front())
			R.push(R.front()+n);
		else
			D.push(D.front()+n);

		R.pop();
		D.pop();
	}

	if(!D.empty())
		cout << 'D';
	else
		cout << 'R';
}