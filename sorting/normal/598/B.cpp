#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s, s2;
	int m;

	cin >> s >> m;

	for(int i = 0; i < m; i++)
	{
		int l, r, k;

		cin >> l >> r >> k;

		l--;
		r--;

		k %= (r-l+1);

		if(k == 0)
			continue;

		s2 = s.substr(r-k+1, k);
		s.erase(r-k+1, k);
		s.insert(l, s2);
	}

	cout << s << "\n";

	return 0;
}