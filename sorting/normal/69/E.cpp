#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int a[N];
map<int, int> Map;
set<int> Set;

int main ()
{
	int n, k;

	cin >> n >> k;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i < k; i++)
	{
		Map[a[i]]++;

		if(Map[a[i]] == 1)
			Set.insert(a[i]);
		else
			if(Map[a[i]]==2)
				Set.erase(a[i]);
	}

	if(Set.empty())
		cout << "Nothing\n";
	else
		cout << *Set.rbegin() << "\n";

	for(int i = k; i < n; i++)
	{
		Map[a[i]]++;

		if(Map[a[i]] == 1)
			Set.insert(a[i]);
		else
			if(Map[a[i]] == 2)
				Set.erase(a[i]);

		Map[a[i-k]]--;

		if(Map[a[i-k]] == 0)
			Set.erase(a[i-k]);
		else
			if(Map[a[i-k]] == 1)
				Set.insert(a[i-k]);

		if(Set.empty())
			cout << "Nothing\n";
		else
			cout << *Set.rbegin() << "\n";
	}

	return 0;
}