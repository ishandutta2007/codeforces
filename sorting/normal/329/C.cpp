#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7; 

map<pair<int, int>, bool> mp;
int perm[N], n;

int my_random(int mx)
{
	int c = (1<<15);

	int res = (rand() % c) * c + (rand()%c);

	return res % mx;
}

int next_num(int x)
{
	if(x == n)
		return 1;

	return x+1;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m;

	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int u, v;

		cin >> u >> v;

		mp[{u, v}] = 1;
		mp[{v, u}] = 1;
	}

	for(int i = 1; i <= n; i++)
		perm[i] = i;

	for(int i = 1; i <= 300; i++)
	{
		random_shuffle(perm+1, perm + n+1, my_random);

		bool solution = true;

		for(int j = 1; j <= m ; j++)
			if(mp.find({perm[j], perm[ next_num(j) ]}) != mp.end())
			{
				solution = false;
				break;
			}

		if(!solution)
			continue;

		for(int j = 1; j <= m; j++)
			cout << perm[j] << " " << perm[ next_num(j) ] << "\n";

		return 0;
	}

	cout << "-1\n";

	return 0;
}