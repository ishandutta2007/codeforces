#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 100100;
const ll INF = 1e16;

int N, Q;
ll val[MAXN];
int color[MAXN];
ll A, B;

bool seen[MAXN]; // if color i is seen
ll bcolor[MAXN]; // best of color [i]
ll b1, b2;
int c1, c2; //values and colors of the top 2 best with diff colors

void solve()
{
	for (int i = 0; i < MAXN; i++)
	{
		seen[i] = false;
		bcolor[i] = -INF;
	}
	b1 = b2 = -INF;
	c1 = c2 = -1;
	
	ll ans = 0;
	
	for (int i = 0; i < N; i++)
	{
		ll aval = B * val[i];
		if (seen[color[i]])
			aval = max (aval, bcolor[color[i]] + A * val[i]);
		if (c1 != color[i])
			aval = max (aval, b1 + B * val[i]);
		else
			aval = max (aval, b2 + B * val[i]);
		
		ans = max (ans, aval);
		
		bcolor[color[i]] = max (aval, bcolor[color[i]]);
		seen[color[i]] = true;
		
		if (aval > b1)
		{
			if (c1 == color[i])
			{
				b1 = aval;
				c1 = color[i];
			}
			else
			{
				b2 = b1;
				c2 = c1;
				b1 = aval;
				c1 = color[i];
			}
		}
		else if (aval > b2 && color[i] != c1)
		{
			b2 = aval;
			c2 = color[i];
		}
	}
	
	cout << ans << "\n";
}

int main()
{
	cin >> N >> Q;
	for (int i = 0; i < N; i++)
		cin >> val[i];
	for (int i = 0; i < N; i++)
		cin >> color[i];
	
	for (int i = 0; i < Q; i++)
	{
		cin >> A >> B;
		solve();
	}
	
	return 0;
}