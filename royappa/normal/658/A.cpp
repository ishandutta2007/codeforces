#include <bits/stdc++.h>

using namespace std;


typedef long long LL;


int main()
{
	int n, c;
	cin >> n >> c;
	vector<int> p(n), t(n);
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
	}
	int L = 0;
	int T = 0;
	for (int i = 0; i < n; i++)
	{
		T += t[i];
		L += max(0, p[i]-T*c);
	}
	int R = 0;
	T = 0;
	for (int i = n-1; i >= 0; i--)
	{
		T += t[i];
		R += max(0, p[i]-T*c);
	}
	cout << (L > R ? "Limak" : (L < R ? "Radewoosh" : "Tie")) << endl;

	exit(0);
}