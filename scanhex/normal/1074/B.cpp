#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

const int N = 1000;
vector<int> g[N];
int de[N];

void d(int u, int p = -1)
{
	for (int v : g[u])
		if (v != p)
			de[v] = de[u] + 1, d(v, u);
}


int qA(int x)
{
	 cout << "A " << x + 1 << endl;
	 int ans;
	 cin >> ans;
	 return ans - 1;
}
int qB(int x)
{
	 cout << "B " << x + 1 << endl;
	 int ans;
	 cin >> ans;
	 return ans - 1;
}

void answer(int x)
{
	 cout << "C " << x + 1 << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		 int n;
		 cin >> n;
		 for (int i = 0; i < n; ++i)
			 g[i].clear();
		 for (int i = 0; i < n - 1; ++i)
		 {
			  int a, b;
			  cin >> a >> b;
			  --a, --b;
			  g[a].push_back(b);
			  g[b].push_back(a);
		 }
		 int k1;
		 cin >> k1;
		 vector<int> xs(k1);
		 for (auto& x : xs)
			 cin >> x, --x;
		 int k2;
		 cin >> k2;
		 vector<int> ys(k2);
		 for (auto& x : ys)
			 cin >> x, --x;
		 int kekos = qB(ys[0]);
		 d(kekos);
		 int mem = -1;
		 for (auto& x : xs)
			 if (mem == -1 || de[x] < de[mem])
				 mem = x;
		 int lol = qA(mem);
		 if (count(ys.begin(), ys.end(), lol))
			 answer(mem);
		 else
			 cout << "C -1" << endl;
	}
	return 0;
}