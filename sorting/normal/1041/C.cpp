#include<bits/stdc++.h>
#include<queue>

using namespace std;

const int N = 2e5 + 7;



pair<int, int> a[N];
int res[N];
int cnt = 1;

struct cmp
{
	bool operator()(int x, int y)
	{
		return a[x] > a[y];
	}
};

priority_queue<int, vector<int>, cmp > q;

int main ()
{
	int n, m, d;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> d;

	for(int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a, a+n);

	q.push(0);
	res[a[0].second] = 1;
	cnt++;

	for(int i = 1; i < n; i++)
	{
		if(a[i].first - a[q.top()].first > d)
		{
			//q.pop();
			//q.push(a[i]);
			res[a[i].second] = res[a[q.top()].second];
			q.pop();
			q.push(i);
		}
		else
		{
			res[a[i].second] = cnt;
			cnt++;
			q.push(i);
		}
	}

	cout << q.size() << "\n";

	for(int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << "\n";

	return 0;
}