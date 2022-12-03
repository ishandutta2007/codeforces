#include <climits>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
 
typedef long long ll;

struct bit {
	vector<ll> v;
	bit(int n) : v(n + 1) {}
	ll sum(int i) {
		ll res = 0;
		for (; i > 0; i -= i & -i) res += v[i];
		return res;
	}
	void add(int i, ll x) {
		for (i++; i < v.size(); i += i & -i) v[i] += x;
	}
	ll get(int l, int r) {
		return sum(r) - sum(l);
	}
};

int main() {
	int n; cin >> n;
	string s; cin >> s;
	for (char& c: s) {
		if (c == 'U') c = '>';
		if (c == 'D') c = '<';
	}
	vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++)
		a[i] = a[i - 1] + (s[i - 1] == '>');
	for (int i = n - 1; i >= 0; i--)
		b[i] = b[i + 1] + (s[i] == '<');
	vector<int> x(n + 1), y(n + 1);
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == '>')
			x[cnt++] = i;
	cnt = 0;
	for (int i = n - 1; i >= 0; i--)
		if (s[i] == '<')
			y[cnt++] = i + 1;
	bit bt1(n), bt2(n);
	for (int i = 0; i < n; i++) {
		if (s[i] == '>') bt1.add(i, i);
		if (s[i] == '<') bt2.add(i, i);
	}
	for (int i = 0; i < n; i++) {
		ll l = a[i], r = b[i + 1], z;
		if (s[i] == '<' && l <= r)
			z = (l * i - bt1.get(0, i) + bt2.get(i + 1, y[r - l]) - l * i) * 2 + i + 1;
		if (s[i] == '<' && l > r)
			z = ((r + 1) * i - bt1.get(x[l - r - 1], i) + bt2.get(i + 1, n) - r * i) * 2 + n - i;
		if (s[i] == '>' && l >= r)
			z = (r * i - bt1.get(x[l - r], i) + bt2.get(i + 1, n) - r * i) * 2 + n - i;
		if (s[i] == '>' && l < r)
			z = (l * i - bt1.get(0, i) + bt2.get(i + 1, y[r - l - 1]) - (l + 1) * i) * 2 + i + 1;
		//cout << z << endl;
		printf("%lld ", z);
	}
	cout << endl;
}