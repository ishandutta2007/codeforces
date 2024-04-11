#include<bits/stdc++.h>

using namespace std;

const int N = 2e3 + 7;

vector<int> v[N];

void ask_C(int a)
{
	cout << "C " << a << endl;
	cout.flush();

	return;
}

int ask_B(int a)
{
	cout << "B " << a << endl;
	cout.flush();

	int res;

	cin >> res;

	return res;
}

int ask_A(int a)
{
	cout << "A " << a << endl;
	cout.flush();

	int res;

	cin >> res;

	return res;
}

bool used[N];
int n, k1, k2;
int x[N], y[N];
bool in_x[N];

void init_in_X()
{
	for(int i = 1; i <= n; i++)
		in_x[i] = false;

	for(int i = 0; i < k1; i++)
		in_x[x[i]] = true;
}

int find_closest(int ans)
{
	queue<int> q;

	for(int i = 1; i <= n; i++)
		used[i] = false;

	q.push(ans);
	used[ans] = true;

	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		if(in_x[u])
			return u;

		for(int i = 0; i < v[u].size(); i++)
		{
			int to = v[u][i];

			if(!used[to])
			{
				q.push(to);
				used[to] = true;
			}
		}
	}

	return -1;
}

void solve()
{
	cin >> n;

	for(int i = 0; i < n-1; i++)
	{
		int a, b;

		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	cin >> k1;

	for(int i = 0; i < k1; i++)
		cin >> x[i];

	cin >> k2;

	for(int i = 0; i < k2; i++)
		cin >> y[i];

	init_in_X();

	int ans = ask_B(y[0]);
	int ans2 = find_closest(ans);
	int ans3 = ask_A(ans2);

	bool in_y = false;

	for(int i = 0; i < k2; i++)
		if(y[i] == ans3)
		{
			in_y = true;
			break;
		}

	if(in_y)
		ask_C(ans2);
	else
		ask_C(-1);

	for(int i = 1; i <= n; i++)
		v[i].clear();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;

	for(int i = 0; i < t; i++)
		solve();

	return 0;
}