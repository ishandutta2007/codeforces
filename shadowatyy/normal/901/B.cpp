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

const int N = 157;

int n;

VI A[N];
VI B[N];
	
VI mult(VI A, VI B)
{
	VI C(A.size()+B.size()-1, 0);

	for(int i = 0; i < A.size(); ++i)
	{
		for(int j = 0; j < B.size(); ++j)
		{
			C[i+j] += A[i]*B[j];
			C[i+j] %= 2;
		}
	}

	return C;
}

void add(VI &A, VI B)
{
	for(int i = 0; i < B.size(); ++i)
	{
		A[i] += B[i];
		A[i] %= 2;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	A[0] = {1};
	B[0] = {0};

	for(int i = 1; i <= n; ++i)
	{
		B[i] = A[i-1];
		A[i] = mult(B[i], {0, 1});
		add(A[i], B[i-1]);
	}

	cout << A[n].size()-1 << endl;

	for(auto it:A[n])
		cout << it << " ";

	cout << endl;

	cout << B[n].size()-1 << endl;

	for(auto it:B[n])
		cout << it << " ";

	cout << endl;
}