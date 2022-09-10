#include <bits/stdc++.h>
#include <unistd.h>
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

#define N 5007

int n, m, r0, r1;

string z, l, rmin, rmax;

map<string, int> M;

int val[N];

string A[N], O[N], B[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> z >> l >> l;
		M[z] = i;
		A[i] = l;

		if(l[0]!='1' && l[0]!='0')
		{
			A[i] = l;
			cin >> O[i] >> B[i];
		}
	}

	M["?"] = 0;

	for(int b = 0; b < m; ++b)
	{
		r0 = 0;
		val[0] = 0;

		for(int i = 1; i <= n; ++i)
		{
			if(O[i]=="AND")
				val[i] = val[M[A[i]]] & val[M[B[i]]];
			else if(O[i]=="OR")
				val[i] = val[M[A[i]]] | val[M[B[i]]];
			else if(O[i]=="XOR")
				val[i] = val[M[A[i]]] ^ val[M[B[i]]];
			else
				val[i] = A[i][b]-'0';

			r0 += val[i];
		}

		r1 = 0;
		val[0] = 1;

		for(int i = 1; i <= n; ++i)
		{
			if(O[i]=="AND")
				val[i] = val[M[A[i]]] & val[M[B[i]]];
			else if(O[i]=="OR")
				val[i] = val[M[A[i]]] | val[M[B[i]]];
			else if(O[i]=="XOR")
				val[i] = val[M[A[i]]] ^ val[M[B[i]]];
			else
				val[i] = A[i][b]-'0';

			r1 += val[i];
		}

		if(r0>=r1)
			rmax += "0";
		else
			rmax += "1";

		if(r0<=r1)
			rmin += "0";
		else
			rmin += "1";
	}	

	cout << rmin << endl << rmax;
}