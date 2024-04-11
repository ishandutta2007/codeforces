#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forv(i, a) forn (i, a.size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((x) * (x))

typedef long long int64;
typedef long double ld;

string s;

int n, al = -1, ar = -1, mx = 0;
vector<char> st;
int sum[100100], last[100100];

void tryOut(int l, int r) {
//	cerr << st.size() << " " << l << " " << r << endl;
	if (mx < sum[r] - sum[l]) {
		mx = sum[r] - sum[l];
		al = l;
		ar = r;
	}
}

int solve(int l) {
	st.clear();
	last[0] = l;
	for (int i = l; i < n; ++i) {
	//	cerr << s[i] << " ";
		if (s[i] == ')') {
			if (st.size() && st.back() == '(') {
				st.pop_back();
				tryOut(last[st.size()], i + 1);
			} else {
				return i + 1;
			}
		} else if (s[i] == ']') {
			if (st.size() && st.back() == '[') {
				st.pop_back();
				tryOut(last[st.size()], i + 1);
			} else {
				return i + 1;
			}
		} else {
			st.pb(s[i]);
			last[st.size()] = i + 1;
		}
	}
	return n;
}

int main() {
	cin >> s;
	n = s.size();
	sum[0] = 0;
	forn (i, n) {
		sum[i + 1] = sum[i] + (s[i] == '[');
	}
	int cur = 0;
	while (cur < n) {
		cur = solve(cur);
	}
	if (al == -1) {
		cout << 0;
		return 0;
	}
	cout << mx << endl;
	for (int i = al; i < ar; ++i) {
		cout << s[i];
	}
}