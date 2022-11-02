#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

typedef long long intl;

const int N = 100011;
intl k[N], b[N];

struct Seg
{
	intl ly, k;
	intl ry;
	bool operator <(Seg rhs) const {
		return tie(ly, k) < tie(rhs.ly, rhs.k);
	}
}seg[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	int x1, x2;
	cin >> x1 >> x2;
	for(int i = 0; i < n; i ++)
	{
		cin >> k[i] >> b[i];
		seg[i] = {x1 * k[i] + b[i], k[i], x2 * k[i] + b[i]};
	}
	sort(seg, seg + n);
	bool flag = true;
	for(int i = 1; i < n; i ++)
		if(seg[i].ly != seg[i - 1].ly && seg[i].ry < seg[i - 1].ry)
			flag = false;
	cout << (flag ? "NO" : "YES") << '\n';
	return 0;
}