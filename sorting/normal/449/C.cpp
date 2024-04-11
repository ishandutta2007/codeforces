#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

bool b[N];
vector<pair<int, int> > res;
vector<int> primes, v;
bool erast[N];

int main ()
{
	int n, pr;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i = 2; i <= n; i++)
		if(!erast[i])
		{
			primes.push_back(i);

			for(int j = 2*i; j <= n; j+=i)
				erast[j] = true;
		}


	for(int i = 1; i < primes.size(); i++)
	{
		v.clear();
		for(int j = primes[i]; j <= n; j += primes[i])
			if(!b[j])
				v.push_back(j);

		if(v.size() % 2 == 0)
			for(int j = 0; j < v.size()/2; j++)
			{
				res.push_back({v[2*j], v[2*j+1]});
				b[v[2*j]] = true;
				b[v[2*j+1]] = true;
			}
		else
		{
			if(v.size() == 1)
				continue;

			res.push_back({v[0], v[2]});
			b[v[0]] = true;
			b[v[2]] = true;
			for(int j = 1; j < v.size()/2; j++)
			{
				b[v[2*j+1]] = true;
				b[v[2*j+2]] = true;
				res.push_back({v[2*j+1], v[2*j+2]});
			}
		}
	}

	v.clear();

	for(int i = 2; i <= n; i+=2)
		if(!b[i])
			v.push_back(i);

	if(v.size() % 2 == 0)
		for(int j = 0; j < v.size()/2; j++)
		{
			res.push_back({v[2*j], v[2*j+1]});
			b[2*j] = true;
			b[2*j+1] = true;
		}
	else
	{
		if(v.size() != 1)
		{

			res.push_back({v[0], v[2]});
			b[v[0]] = true;
			for(int j = 1; j < v.size()/2; j++)
			{
				b[v[2*j+1]] = true;
				b[v[2*j+2]] = true;
				res.push_back({v[2*j+1], v[2*j+2]});
			}

		}
	}

	//for(int i = 2; i <= n; i++)
	//	if(!b[i])
	//		cout << i << endl;
 
	cout << res.size() << "\n";

	for(int i = 0; i < res.size(); i++)
		cout << res[i].first << " " << res[i].second << "\n";

	return 0;
}