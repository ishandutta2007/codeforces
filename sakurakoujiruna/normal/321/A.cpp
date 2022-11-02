#include <bits/stdc++.h>
using namespace std;

const int N = 111;
typedef long long ll;
ll px[N], py[N];

int main() {
	ios :: sync_with_stdio(false);
	ll x, y; cin >> x >> y;
	string s; cin >> s;
	int n = s.size();
	for(int i = 0; i < s.size(); i ++)
		if(s[i] == 'R') px[i] ++;
		else if(s[i] == 'U') py[i] ++;
		else if(s[i] == 'L') px[i] --;
		else py[i] --;
	partial_sum(px, px + n, px);
	partial_sum(py, py + n, py);

	auto check = [](ll x, ll y, ll mx, ll my) {
		if(!x && !y) return !mx && !my;
		if(!x) return !mx && y * my >= 0 && my % y == 0;
		if(!y) return !my && x * mx >= 0 && mx % x == 0;
		int t = mx / x;
		return t >= 0 && x * t == mx && y * t == my;
	};
	bool flag = check(px[n - 1], py[n - 1], x, y);
	for(int i = 0; i < n; i ++)
		if(check(px[n - 1], py[n - 1], x - px[i], y - py[i])) flag = true;
	cout << (flag ? "Yes" : "No") << '\n';
	return 0;
}