#include <bits/stdc++.h>

using namespace std;

int n, a[123], b[123];
int as, bs;
bool v[11212];
int va[11212];
int vb[11212];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> a[i]; as += a[i]; }
	for (int i = 0; i < n; i++) { cin >> b[i]; bs += b[i]; }
	//cout << as << '\n';
	//cout << bs << '\n';

	v[0] = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = bs; j >= b[i]; j--)
		{
			if (v[j-b[i]])
			{
				if (v[j])
				{
					if (vb[j-b[i]] + 1 > vb[j]) continue;
					if (vb[j-b[i]] + 1 == vb[j] && va[j-b[i]] + a[i] <= va[j]) continue;
				}
				v[j] = true;
				va[j] = va[j-b[i]] + a[i];
				vb[j] = vb[j-b[i]] + 1;
			}
		}
	}

	int ba = -1, bb = -1;
	for (int i = as; i <= bs; i++)
	{
		if (v[i])
		{
			if (ba == -1 || vb[i] < bb || (vb[i] == bb && va[i] > ba))
			{
				bb = vb[i];
				ba = va[i];
			}
		}
	}
	cout << bb << ' ' << as - ba << '\n';
	return 0;
}