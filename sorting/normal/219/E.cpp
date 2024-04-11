#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

set<int> parking_spaces;
set<tuple<int, int, int> > distances;

int where[N];

int n;

int calc_dist(int l, int r)
{
	if(l > r)
		swap(l, r);

	int d = (r-l) / 2;

	if(l == 0 || r == n+1)
		d = r - l - 1;

	return d;
}

void dist_insert(int l, int r)
{
	distances.insert( make_tuple(calc_dist(l, r), n + 1 - l, r) );
}

void dist_erase(int l, int r)
{
	distances.erase( make_tuple(calc_dist(l, r), n + 1- l, r) );
}

int main ()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m;

	cin >> n >> m;

	parking_spaces.insert(0);
	parking_spaces.insert(n+1);
	
	dist_insert(0, n+1);

	for(int i = 0; i < m; i++)
	{
		//cout << distances.size() << " dist\n";

		int type, id;

		cin >> type >> id;

		if(type == 1)
		{
			//add
			tuple<int, int, int> t = *distances.rbegin();

			int l = n + 1 - get<1>(t);
			int r = (int) get<2>(t);

			if(l == 0)
			{
				cout << "1\n";
				parking_spaces.insert(1);
				where[id] = 1;
				dist_erase(l, r);
				dist_insert(l, 1);
				dist_insert(1, r);

				continue;
			}

			if(r == n+1)
			{
				cout << n << "\n";
				parking_spaces.insert(n);
				where[id] = n;
				dist_erase(l, r);
				dist_insert(l, n);
				dist_insert(n, r);

				continue;
			}

			where[id] = (l + r) / 2;
			cout << where[id] << "\n";
			parking_spaces.insert(where[id]);
			dist_erase(l, r);
			dist_insert(l, where[id]);
			dist_insert(where[id], r);
		}
		else
		{	//remove
			auto it_mid = parking_spaces.lower_bound(where[id]);
			auto it_l = it_mid;
			auto it_r = it_mid;
			it_l--;
			it_r++;

			int val_mid = *it_mid, val_l = *it_l, val_r = *it_r;

			dist_insert(val_l, val_r);
			dist_erase(val_l, val_mid);
			dist_erase(val_mid, val_r);

			parking_spaces.erase(where[id]);
		}


	}

	return 0;
}