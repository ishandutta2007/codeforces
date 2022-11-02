#include <iostream>
#include <vector>
using namespace std;

const int N = 1011111;

int p[N];
bool vis[N];
vector <int> last[N];
int ans[N];

void solve_odd(vector <int> &v)
{
	int l = v.size();
	for(int i = 0; i < v.size(); i ++)
		ans[v[i]] = v[(i + l / 2 + 1) % l];
}

void solve_even(vector <int> &v1, vector <int> &v2)
{
	int l = v1.size();
	for(int i = 0; i < v1.size(); i ++)
	{
		ans[v1[i]] = v2[i];
		ans[v2[i]] = v1[(i + 1) % l];
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> p[i];
	for(int i = 1; i <= n; i ++)
		if(!vis[i])
		{
			vector <int> vec;
			for(int j = i; !vis[j]; j = p[j])
			{
				vis[j] = true;
				vec.push_back(j);
			}
			int l = vec.size();
			if(l & 1)
				solve_odd(vec);
			else
			{
				if(last[l].size() != 0)
				{
					solve_even(vec, last[l]);
					last[l].clear();
				}
				else
					last[l] = vec;
			}
		}
	bool flag = true;
	for(int i = 1; i <= n; i ++)
		if(last[i].size() != 0)
			flag = false;
	if(flag)
	{
		for(int i = 1; i <= n; i ++)
			cout << ans[i] << ' ';
		cout << '\n';
	}
	else
		cout << -1 << '\n';
	return 0;
}