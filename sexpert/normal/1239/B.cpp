#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, sum = 0, mn = 0, pos = 0;
	string s;
	cin >> n >> s;
	for(int i = 0; i < n; i++) {
		if(sum < mn) {
			mn = sum;
			pos = i;
		}
		sum += (s[i] == '(');
		sum -= (s[i] == ')');
	}
	if(sum != 0) {
		cout << "0\n1 1\n";
		return 0;
	}
	rotate(s.begin(), s.begin() + pos, s.end());
	//cout << s << endl;
	sum = 0;
	vector<int> bal;
	for(auto c : s) {
		bal.push_back(sum);
		sum += (c == '(') - (c == ')');
	}
	bal.push_back(0);
	//for(auto x : bal)
	//	cout << x << " ";
	//cout << '\n';
	int ans = 0, c0 = 0, al = 1, ar = 1;
	for(auto x : bal)
		ans += (x == 0);
	ans--;
	c0 = ans;
	int la = 0, cur = 0;
	for(int i = 0; i <= n; i++) {
		if(bal[i] == 0) {
			if(cur > ans) {
				ans = cur;
				al = la + 1, ar = i;
			}
			cur = 0;
			la = i;
		}
		if(bal[i] == 1)
			cur++;
	}
	cur = 0, la = 0;
	for(int i = 0; i <= n; i++) {
		if(bal[i] < 2) {
			if(cur + c0 > ans) {
				ans = cur + c0;
				al = la + 1, ar = i;
			}
			cur = 0;
			la = i;
		}
		if(bal[i] == 2)
			cur++;
	}
	al += pos;
	ar += pos;
	if(al > n)
		al -= n;
	if(ar > n)
		ar -= n;
	cout << ans << '\n';
	cout << al << " " << ar << '\n';
}