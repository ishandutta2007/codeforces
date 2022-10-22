#include <bits/stdc++.h>

using namespace std;

int main()
{
	int h, w;
	cin >> w >> h;
	vector<string> matr(h);
	for (auto& x : matr)
		cin >> x;
	for (int i = 0; i < 2 * w; ++i)
		for (int j = 0; j < 2 * h; ++j)
		{
			cout << matr[j / 2][i / 2];
			if (j + 1 == 2 * h)
				cout << '\n';
		}
}