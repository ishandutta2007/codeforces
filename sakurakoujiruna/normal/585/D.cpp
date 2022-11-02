#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int Inf = 0x3f3f3f3f;

struct Element
{
	int a, b, c;
	Element() { }
	Element(int a, int b, int c) : a(a), b(b), c(c) { }
	bool operator <(const Element &rhs) const
	{
		if(a == rhs.a)
		{
			if(b == rhs.b)
				return c < rhs.c;
			return b < rhs.b;
		}
		return a < rhs.a;
	}
};

string str[] = {"LM", "LW", "MW"};

const int N = 25;
int a[N], b[N], c[N];

int ans = -Inf;
pair <int, vector <int> > ret;

void dfs(int cur, int goal, int sa, int sb, int sc, vector <int> &vec, map <Element, pair <int, vector <int> > > &mp, bool &flag)
{
	if(cur == goal)
		if(goal == vec.size())
		{
			if(mp.find(Element(sa - sb, sb - sc, 0)) != mp.end())
			{
				flag = true;
				pair <int, vector <int> > old = mp[Element(sa - sb, sb - sc, 0)];
				if(old.first - sa > ans)
				{
					ans = old.first - sa;
					for(int i = 0; i < goal / 2; i ++)
						vec[i] = old.second[i];
					ret = make_pair(old.first - sa, vec);
				}
			}
		}
		else
		{
			if(mp.find(Element(sa - sb, sb - sc, 0)) == mp.end())
				mp[Element(sa - sb, sb - sc, 0)] = make_pair(sa, vec);
			else if(mp[Element(sa - sb, sb - sc, 0)].first < sa)
				mp[Element(sa - sb, sb - sc, 0)] = make_pair(sa, vec);
		}
	else
	{
		vec[cur] = 0;
		dfs(cur + 1, goal, sa + a[cur], sb + b[cur], sc, vec, mp, flag);
		vec[cur] = 1;
		dfs(cur + 1, goal, sa + a[cur], sb, sc + c[cur], vec, mp, flag);
		vec[cur] = 2;
		dfs(cur + 1, goal, sa, sb + b[cur], sc + c[cur], vec, mp, flag);
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i] >> b[i] >> c[i];
		if(i >= n / 2)
		{
			a[i] = -a[i];
			b[i] = -b[i];
			c[i] = -c[i];
		}
	}
	bool flag = false;
	vector <int> vec(n / 2);
	map <Element, pair <int, vector <int> > > mp;

	vec = vector <int> (n);
	dfs(0, n / 2, 0, 0, 0, vec, mp, flag);
	dfs(n / 2, n, 0, 0, 0, vec, mp, flag);

	if(!flag)
		cout << "Impossible\n";
	else
	{
		//cout << ans << '\n';
		for(int i = 0; i < n; i ++)
			cout << str[ret.second[i]] << '\n';
	}

	return 0;
}