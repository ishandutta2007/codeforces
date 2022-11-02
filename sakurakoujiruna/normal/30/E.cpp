#include <iostream>
#include <algorithm>
using namespace std;

struct Ans
{
	int p1, l1;
	int p2, l2;
	int p3, l3;
	bool operator <(Ans a) {
		return l1 + l2 + l3 < a.l1 + a.l2 + a.l3;
	}
	void update(Ans a) {
		if(*this < a)
			*this = a;
	}
	void print() {
		if(l1 == 0)
			cout << "1\n" << p2 << ' ' << l2 << '\n';
		else
		{
			cout << 3 << '\n';
			cout << p1 << ' ' << l1 << '\n';
			cout << p2 << ' ' << l2 << '\n';
			cout << p3 << ' ' << l3 << '\n';
		}
	}
};

const int N = 200011;
char c[N], rc[N];

int r[N];
void manacher(int n, string s, int r[]) // $#a#b#a#@
{
	static char c[N];
	for(int i = 0; i < n; i ++)
	{
		c[2 * i + 1] = '#';
		c[2 * i + 2] = s[i];
	}
	c[2 * n + 1] = '#';
	c[0] = '$';
	c[2 * n + 2] = '@';
	int p = 0, mx = 0;
	for(int i = 0; i < 2 * n + 3; i ++)
	{
		if(mx > i)
			r[i] = min(mx - i, r[2 * p - i]);
		else
			r[i] = 1;
		while(c[i + r[i]] == c[i - r[i]])
			r[i] ++;
		if(i + r[i] > mx)
		{
			mx = i + r[i];
			p = i;
		}
	}
}

int p[N], match[N], mp[N];

int main()
{
	ios :: sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	manacher(n, s, r);
	for(int i = 0; i < n; i ++)
		rc[i + 1] = c[i + 1] = s[i];
	reverse(rc + 1, rc + n + 1);

	int last = 0;
	for(int i = 2; i <= n; i ++)
	{
		while(last > 0 && rc[last + 1] != rc[i])
			last = p[last];
		if(rc[last + 1] == rc[i])
			last ++;
		p[i] = last;
	}
	last = 0;
	for(int i = 1; i <= n; i ++)
	{
		while(last > 0 && rc[last + 1] != c[i])
			last = p[last];
		if(rc[last + 1] == c[i])
			last ++;
		match[i] = last;
		mp[i] = i;
		if(match[i - 1] > match[i])
		{
			mp[i] = mp[i - 1];
			match[i] = match[i - 1];
		}
	}

	Ans ans = {0, 0, 0, 0, 0, 0};
	for(int i = 1; i <= n; i ++)
	{
		int tr = r[2 * i] / 2;
		int left = i - tr + 1;
		int right = i + tr - 1;
		if(left == 0)
			ans.update({0, 0, left, tr * 2 - 1, 0, 0});
		else
		{
			int l = min(match[left - 1], n - right);
			ans.update({mp[left - 1] - match[left - 1] + 1, l,
				left, tr * 2 - 1, n - l + 1, l});
		}
	}
	ans.print();
	return 0;
}