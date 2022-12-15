#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

vector<int> a[N];
vector<int> left_v;

bool cmp(int a, int b)
{
	return a > b;
}

int cnt;

void pop_left(int ind)
{
	swap(left_v[ind], left_v[cnt-1]);
	cnt--;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	cnt = m;

	for(int i = 0; i < n ; i++)
	{
		int s, r;

		cin  >> s >> r;

		a[s].push_back(r);
	}

	for(int i = 1; i <= m; i++)
		left_v.push_back(i);

	for(int i = 1; i <= m; i++)
		sort(a[i].begin(), a[i].end(), cmp);
	for(int i = 1; i <= m; i++)
		for(int j = 1; j < a[i].size(); j++)
			a[i][j] += a[i][j-1];

	int res = 0;

	for(int i = 1; i <= n; i++)
	{
		int curr_res = 0;

		//cout << i << " i" << endl;

		for(int j = 0; j < cnt; j++)
		{
			int x = left_v[j];

			//cout << x << endl;

			if(a[x].size() < i)
			{
				//cout << "pop " << x << endl;
				pop_left(j);
				j--;
				continue;
			}
			if(a[x][i-1] < 0)
			{
				//cout << "pop " << x << endl;
				pop_left(j);
				j--;
				continue;
			}
			curr_res += a[x][i-1];

			//cout << curr_res << " curr_res\n"; 
		}
		res = max(res, curr_res);
	}

	cout << res << "\n";

	return 0;
}