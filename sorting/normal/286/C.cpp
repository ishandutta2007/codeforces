#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

const int N = 1e6 + 7;

int a[N];
int n;

void Yes()
{
	cout << "YES\n";
	for(int i = 0; i < n-1; i++)
		cout << a[i] << " ";
	cout << a[n-1] << "\n";

	exit(0);
}

void No()
{
	cout << "NO\n";

	exit(0);
}

stack<int> st;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	int m;

	cin >> m;

	for(int i = 0; i < m; i++)
	{
		int x;

		cin >> x;

		x--;

		a[x] = -a[x];
	}

	for(int i = n-1; i >= 0; i--)
	{
		if(a[i] < 0)
			st.push(a[i]);
		else
		{
			if(!st.empty() && st.top() == -a[i])
				st.pop();
			else
			{
				a[i] = -a[i];
				st.push(a[i]);
			}
		}
	}

	if(st.empty())
		Yes();
	else
		No();

	return 0;
}