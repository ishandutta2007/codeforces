#include<bits/stdc++.h>

using namespace std;

void solve()
{
	int d;

	cin >> d;

	long double D = (long double) d*d - 4*d;

	if(D < 0)
	{
		cout << "N\n";

		return;
	}

	D = (long double)sqrt(D);

	if(d < D)
	{
		cout << "N\n";
		return;
	}

	cout << "Y ";
	cout << fixed << setprecision(10) << (long double)(d+D)/2.0 << " " << (long double)(d-D)/2.0 << "\n";

	return ;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;

	for(int i = 0; i < t; i++)
		solve();

	return 0;
}