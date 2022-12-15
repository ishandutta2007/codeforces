#include<bits/stdc++.h>

using namespace std;

const int N = 507;

int a[N];
int curr[N];
vector<int> stick;
vector<pair<int, int> > adj;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, sum = 0;

	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
		curr[i] = a[i];
	}

	if(sum < (n-1)*2)
	{
		cout << "NO\n";

		return 0;
	}

	int res = 0;

	for(int i = 1; i <= n; i++)
		if(a[i] >= 2)
		{
			if(!stick.empty())
			{
				adj.push_back({stick.back(), i});
				curr[i] --;
				curr[stick.back()] --;
			}
			stick.push_back(i);
		}

	res = stick.size();

	int cnt = 0;

	for(int i = 1; i <= n; i++)
		if(a[i] == 1)
			cnt ++;

	res += min(cnt, 2);

	int j = 0;
	int i = 1;

	for(; i <= n; i++)
		if(a[i] == 1)
		{
			adj.push_back({i, stick.back()});
			curr[i] --;
			curr[stick.back()]--;
			i++;
			break;
		}


	for(; i <= n; i++)
		if(a[i] == 1)
		{
			while(!curr[stick[j]])
				j++;
			adj.push_back({i, stick[j]});
			curr[i] --;
			curr[stick[j]] --;
		}

	cout << "YES " << res-1 << "\n";

	cout << adj.size() << "\n";

	for(i = 0; i < adj.size(); i++)
		cout << adj[i].first << " " << adj[i].second << "\n";

	return 0;
}