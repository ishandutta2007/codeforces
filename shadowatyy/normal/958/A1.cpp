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

int n;

vector<VI> A, B;

set<vector<VI> > vis;

void go(vector<VI> v)
{
	if(vis.find(v)!=vis.end())
		return;

	vis.insert(v);

	auto u1 = v, u2 = v, u3 = v;

	for(int i = 0; i < n-1-i; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			swap(u1[j][i], u1[j][n-1-i]);
			swap(u2[i][j], u2[n-1-i][j]);
		}
	} 

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			u3[j][n-1-i] = v[i][j];
		}
	}

	go(u1);
	go(u2);
	go(u3);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	A.resize(n);
	B.resize(n);

	for(int i = 0; i < n; ++i)
	{
		A[i].resize(n);
		B[i].resize(n);
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			char c;
			cin >> c;
			A[i][j] = c;
		}
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			char c;
			cin >> c;
			B[i][j] = c;
		}
	}

	go(A);

	if(vis.find(B)==vis.end())
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
}