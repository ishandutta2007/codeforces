#include<bits/stdc++.h>
#include<unordered_map>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

const long long N = 1e5 + 7;
const long long maxi = 1e9;

long long a[N], b[N];

unordered_map<long long, long long> Map[2][35], t;

int main ()
{
	long long n, y1ll, m, y2;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> y1ll;

	for(long long i = 0; i < n; i++)
	{
		cin >> a[i];

		t[a[i]] = 1;

		//cout << i <<endl;
		for(long long j = 0; (1ll<<j) <= maxi; j++)
			Map[0][j][a[i]%(1ll<<j)]++;
	}

	cin >> m >> y2;

	long long res = 0;

	for(long long i = 0; i < m; i++)
	{
		cin>>b[i];
		//cout << i <<endl;
		for(long long j = 0; (1ll<<j) <= 2*maxi; j++)
		{
			//cout << j <<endl;
			Map[1ll][j][b[i]%(1ll<<j)]++;
		}

		if(t[b[i]])
			res = 2;
	}

	//cout << "here" << endl;

	for(long long i = 0; i < n; i++)
	{
		//cout << i  << endl;
		for(long long j = 0; (1ll<<j) <= maxi; j++)
		{
			res = max(res, Map[0][j+1][a[i]%(1ll<<(j+1))] + Map[1ll][j+1ll][( a[i]%(1ll<<(j+1)) + (1ll<<j) ) %(1ll<<(j+1))]);
			//cout << Map[0][j+1][a[i]%(1ll<<(j+1))] << " - "  << Map[1ll][j+1ll][( a[i]%(1ll<<(j+1)) + (1ll<<j) ) %(1ll<<(j+1))] << "\n";
			//cout << i << " " << j << " " << res <<endl;
		}
	}

	for(long long i = 0; i < m; i++)
	{
		////cout << i  << endl;
		for(long long j = 0; (1ll<<j) <= maxi; j++)
		{
			res = max(res, Map[1][j+1][b[i]%(1ll<<(j+1))] + Map[0][j+1ll][( b[i]%(1ll<<(j+1)) + (1ll<<j) ) %(1ll<<(j+1))]);
			//cout << Map[0][j+1][a[i]%(1ll<<(j+1))] << " - "  << Map[1ll][j+1ll][( a[i]%(1ll<<(j+1)) + (1ll<<j) ) %(1ll<<(j+1))] << "\n";
			//cout << i << " " << j << " " << res <<endl;
		}
	}

	cout << res << "\n";

	return 0;
}