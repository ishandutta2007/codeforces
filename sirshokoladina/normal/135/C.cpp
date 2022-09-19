#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <assert.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define forin(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define all(a) a.begin(), a.end()
#define fs first
#define sc second
#define elif else if
#define sqr(a) ((a) * (a))
#define mp make_pair
#define pb push_back
#define last(a) (*(a).end())
#define fill_zero(a) memset(a, 0, sizeof(a))
#define y1 botva
#define count botven
#define norm(a) a.erase(unique(all(a)), a.end());

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;

int calc3(string s) {
	int a0 = 0, a1 = 0, a2 = 0;
	forn (i, s.size()) {
		if (s[i] == '0') {
			a0++;
		}
		if (s[i] == '1') {
			a1++;
		}
		if (s[i] == '?') {
			a2++;
		}
	}
	int ans = 0;
	if (s.size() % 2) {
		if (a0 + a2 + 1 > a1) {
			ans += 1;
		}
		if (a1 + a2 > a0 + 1) {
			ans += 8;
		}
		if (a0 + a2 + 1 >= a1 && a1 + a2 >= a0 + 1) {
			ans += (1 << (2 - (s[s.size() - 1] - '0')));
		}
	} else {
		if (a0 + a2 > a1) {
			ans += 1;
		}
		if (a1 + a2 > a0) {
			ans += 8;
		}
		if (a0 + a2 >= a1 && a1 + a2 >= a0) {
			ans += (1 << (2 - (s[s.size() - 1] - '0')));
		}
	}
	return ans;
}

int calc2(string s) {
	int ans = 0;
	string t = s;
	if (s[s.size() - 2] != '1') {
		t[s.size() - 2] = '0';
		ans |= calc3(t);
	}
	if (s[s.size() - 2] != '0') {
		t[s.size() - 2] = '1';
		ans |= calc3(t);
	}
	return ans;
}

int calc1(string s) {
	int ans = 0;
	string t = s;
	if (s[s.size() - 1] != '1') {
		t[s.size() - 1] = '0';
		ans |= calc2(t);
	}
	if (s[s.size() - 1] != '0') {
		t[s.size() - 1] = '1';
		ans |= calc2(t);
	}
	return ans;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	string s;
	getline(cin, s);
	int x = calc1(s);
	forn (i, 4) {
		if (x & (1 << i)) {
			cout << i / 2 << i % 2 << endl;
		}
	}
	return 0;
}