#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int a[N], b[N], where[N];

multiset<int> pos, neg;
vector<pair<int, int> > change[N], change2[N];

bool used[N];

int n;

int push_1(int prev, int val, int pos)
{
	int when = n-pos;

	int res = val - 1 + (when+1);

	change[when].push_back({prev, res});

	//cout << when << " change1 " << prev << "  - " << res << " " << pos <<  endl; 

	return res;
}

int push_2(int prev, int val, int pos)
{
	int when;

	//if(val == pos)
	//	return 0;

	if(val > pos)
		when = val - pos - 1;
	else
		when = n - pos + val - 1;


	int res = - (when+1);

	change2[when].push_back({prev, res});

	//cout << when << " change2 " << prev << "  - " << res  << " " << pos  << endl; 

	return res;
}

int ind_in_a[N];

int main ()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ind_in_a[ a[i] ] = i;
	}
	for(int i = 1; i <= n; i++)
		cin >> b[i];

	for(int i = 1; i <= n; i++)
	{
		b[i] = ind_in_a[b[i]];
		//cout << b[a[i]] << " i\n";
	}

	reverse(b+1, b+1+n);

	for(int i = 1; i <= n; i++)
	{
		b[i] = n+1 - b[i];
		//cout << b[i] << " b[i]\n";
	}



	for(int i = 1; i <= n; i++)
		if(b[i] <= i)
			pos.insert(i - b[i]);
		else
			neg.insert(b[i] - i);

	//cin.get();
	//cin.get();

	for(int i = 1; i <= n; i++)
	{

		if(b[i] <= i)
		{
			int prev = i - b[i];

			//pos
			prev = push_1(prev, b[i], i);
			//neg
			prev = push_2(prev, b[i], i);
			//pos
		}
		else
		{
			int prev = b[i] - i;

			//neg
			prev = push_2(prev, b[i], i);
			//pos
			prev = push_1(prev, b[i], i);
			//neg
		}
	}

	/*for(int i = 0; i < n; i++)
		for(pair<int, int> p: change[i])
			cout << "change " << i << " - " << p.first << " " << p.second << endl;

	for(int i = 0; i < n; i++)
		for(pair<int, int> p: change2[i])
			cout << "change2 " << i << " - " << p.first << " " << p.second << endl;*/


	for(int i = 0; i < n; i++)
	{
		if(pos.empty())
			cout << *neg.begin()-i << "\n";
		else
		{
			if(neg.empty())
				cout << *pos.begin()+i << "\n";
			else
				cout << min(*neg.begin()-i, *pos.begin()+i) << "\n";
		}

		int ind = 0;

		for(pair<int, int> p: change2[i])
		{
			auto it = neg.find(p.first);
			if(it != neg.end())
			{	
				*neg.erase(it);
				pos.insert(p.second);
				used[ind] = true;
				//cout << p.first << " change2 " << p.second << endl;
			}

			
			ind++;
		}

		for(pair<int, int> p: change[i])
		{
			auto it = pos.find(p.first);
			pos.erase(it);
			neg.insert(p.second);

			//cout << p.first << " change1 " << p.second << endl;
		}

		ind = 0;

		for(pair<int, int> p: change2[i])
		{
			auto it = neg.find(p.first);
			if(!used[ind])
			{	
				*neg.erase(it);
				pos.insert(p.second);
				//cout << p.first << " change2 " << p.second << endl;
			}
			else
				used[ind] = false;

			
			ind++;
		}

	}
	
	return 0;
}