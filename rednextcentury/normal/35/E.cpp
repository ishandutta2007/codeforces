#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int Max = 5e5 + 3, Mod = 1e9 + 7;
 
const int N = 5e5 + 10, mod = 7340033.;
 
int n;
typedef pair<int, int> p2;
vector<p2> ans;
multiset<int> s;
vector<pair<p2, int>> v;
 
bool cmp(pair<p2, int>& a, pair<p2, int>& b)
{
	int x1 = a.first.first, t1 = a.first.second, h1 = a.second;
	int x2 = b.first.first, t2 = b.first.second, h2 = b.second;
	if (x1 != x2)
		return x1 < x2;
	if (t1 != t2)
		return t1 < t2;
	if (t1)
		return h1 > h2;
	return h1 < h2;
 
}
 
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int l, r, h;
		cin >> h >> l >> r;
		v.push_back({ {l,0},-h });
		v.push_back({ {r,1},h });
	}
	sort(v.begin(), v.end());
	int x = -2e9, y = 0;
	s.insert(0);
	for (auto i : v)
	{
		int X = i.first.first;
		int t = i.first.second;
		int h = abs( i.second) ;
		if (t == 0)
		{
			s.insert(h);
			if (x < X && y < h)
			{
				ans.push_back({ X,y });
				ans.push_back({ X,h });
				x = X;
				y = h;
			}
		}
		else
		{
			s.erase(s.find(h));
			int mx = *s.rbegin();
			if (mx < y)
			{
				ans.push_back({ X,y });
				ans.push_back({ X,mx });
				x = X;
				y = mx;
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto i : ans)
		cout << i.first << ' ' << i.second << '\n';
	return 0;
}