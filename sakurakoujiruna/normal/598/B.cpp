#include <iostream>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

int main()
{
	ios :: sync_with_stdio(false);
	string str;
	cin >> str;
	int n = str.size();
	rope <char> rp;
	for(int i = 0; i < n; i ++)
		rp += str[i];
	int q;
	cin >> q;
	while(q --)
	{
		int l, r, s;
		cin >> l >> r >> s;
		l --;
		s %= (r - l);
		rp = rp.substr(0, l) + rp.substr(r - s, s) + rp.substr(l, r - s - l) + rp.substr(r, n - r);
	}
	for(int i = 0; i < n; i ++)
		cout << rp[i];
	cout << '\n';
	return 0;
}