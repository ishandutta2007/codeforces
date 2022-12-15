#include<bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 7;
const long long M = 17;

long long a[M][N];
long long adj[N];
//vector<long long> adj2[N];

bool used[N];
int actual[N];

int main ()
{
	long long n, m;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	if(n == 1)
	{
		cout << "1" << endl;

		return 0;
	}

	for(long long i = 0; i < m; i++)
		for(long long j = 0; j < n; j++)
			cin >> a[i][j];

	for(long long j = 0; j < n; j++)
		actual[a[0][j]] = j;

	for(long long i = 0; i < m; i++)
	{
		for(long long j = 0; j < n-1; j++)
		{
			if(i == 0)
				adj[ actual[a[i][j]] ] = actual[a[i][j+1]];
			else
				if(adj[ actual[a[i][j]] ] != actual[a[i][j+1]])
					adj[ actual[a[i][j]] ] = -1;
		}
		adj[ actual[a[i][n-1]] ] = -1;
	}

	long long start = 0ll;
	long long res = 0ll;
	for(long long i = 0; i < n-1; i++)
		if(adj[i] == -1)
		{
			res += (long long)(i-start+1ll)*(i-start+2ll)/2ll;
			start = i+1;
			//cout << i << endl;
		}

	res += (long long)(n-start)*(n-start+1ll)/2ll;

	cout << res << "\n";

	return 0;
}