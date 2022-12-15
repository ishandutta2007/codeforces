#include<bits/stdc++.h>

using namespace std;

const long long MAXN = 1e5 + 7;

long long a[MAXN];

set<pair<long long, long long> > starts[20];
long long curr_res;

void update(long long ind, long long val)
{
	for(int j = 0; j < 20; j++)
	{
		int pow =  (1<<j);

		if((val & pow) == (a[ind] & pow))
			continue;

		if(val & pow)
		{
			pair<long long, long long> p = {ind, ind};

			auto it = starts[j].lower_bound(p);
			if(it != starts[j].begin())
			{
				it--;
				if(it->second == ind-1)
				{
					curr_res -= (it->second - it->first+1)*(it->second - it->first + 2)/2*pow;

					p.first = it->first;
					starts[j].erase(it);
				}
			}

			it = starts[j].lower_bound({ind, ind});

			if(it != starts[j].end())
			{
				if(it->first == ind+1)
				{
					curr_res -= (it->second - it->first+1)*(it->second - it->first + 2)/2*pow;

					p.second = it->second;
					starts[j].erase(it);
				}
			}

			curr_res += (p.second - p.first+1)*(p.second - p.first + 2)/2*pow;
			starts[j].insert(p);
		}
		else
		{
			pair<long long, long long> p = {ind, ind};

			auto it = starts[j].upper_bound(p);

			if(it == starts[j].end() || it->first > ind)
				it--;

			p = *it;
			starts[j].erase(it);

			//cout << p.first << " - " << p.second << endl;

			curr_res -= (p.second - p.first + 1)*(p.second - p.first + 2)/2*pow;

			pair<long long, long long> p1, p2;

			p1.first = p.first;
			p1.second = ind-1;
			p2.first = ind+1;
			p2.second = p.second;

			if(p1.first <= p1.second)
			{
				starts[j].insert(p1);
				curr_res += (p1.second - p1.first + 1)*(p1.second - p1.first + 2)/2*pow;
			}

			if(p2.first <= p2.second);
			{
				starts[j].insert(p2);
				curr_res += (p2.second - p2.first + 1)*(p2.second - p2.first + 2)/2*pow;
			}
		}

		//if(j < 3)
		//	cout << curr_res << " curr_res" <<"\n";
	}

	a[ind] = val; 
}

int main ()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	long long n, m;

	cin >> n >> m;

	for(long long i = 1; i <= n; i++)
		cin >> a[i];
	
	for(long long j = 0; j < 20; j++)
	{
		long long pow = (1<<j);

		for(long long i = 1; i <= n; i++)
			if((a[i] & pow))
			{
				if(!(a[i-1] & pow))
				{
					starts[j].insert({i,i});
					curr_res += pow;
				}
				else
				{
					pair<long long, long long> p;

					p = *starts[j].rbegin();
					starts[j].erase(*starts[j].rbegin());

					p.second++;
					starts[j].insert(p);

					curr_res += (p.second-p.first+1)*pow;
				}
			}
	}

	for(long long i = 1; i <= m; i++)
	{
		long long p, v;

		cin >> p >> v;

		update(p, v);

		cout << curr_res << "\n";
	}

	return 0;
}