#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& x : a)
		cin >> x;
	sort(a.begin(), a.end());
	int MX = 100001;
	vector<int> cnt(MX);
	for (int x : a)
		++cnt[x];
	int curcnt = 0;
	for (int i = MX - 1; i >= 0; --i)
	{
		curcnt += cnt[i];
		if (curcnt & 1)
		{
			cout << "Conan" << endl;
			return 0;
		}
	}
	cout << "Agasa" << endl;
}