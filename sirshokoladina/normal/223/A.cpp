#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <memory.h>
#include <ctime>
#include <cctype>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define all(a) a.begin(), a.end()
#define sqr(a) ((a) * (a))

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld PI = 3.141592653589793238462643l;

int r[100010];

bool ch(char a, char b) {
	if (a == '(' && b == ')') {
		return 1;
	}
	if (a == '[' && b == ']') {
		return 1;
	}
	return 0;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	string s;
	getline(cin, s);
	vector<pii> v(0);
	forn (i, s.size()) {
		if (s[i] == '(' || s[i] == '[') {
			v.pb(mp(i, 0));
		} else {
			if (!v.size()) {
				s[i] = '!';
			} else {
				int j = v[v.size() - 1].fs;
				bool w = v[v.size() - 1].sc;
				v.pop_back();
				if (!ch(s[j], s[i]) || w) {
					s[j] = s[i] = '!';
					if (v.size()) {
						v[v.size() - 1].sc = 1;
					}
				} else {
					r[j] = i;
				}
			}
		}
	}
	cerr << s << endl;
	forn (i, v.size()) {
		s[v[i].fs] = '!';
	}
	int ans = -1;
	string anss = "";
	forn (i, s.size()) {
		if (s[i] == '!') {
			continue;
		}
		if (i != 0 && s[i - 1] != '!') {
			continue;
		}
		int j = i;
		string t = "";
		t += s[j];
		int k = (s[j] == '[');
		while (j + 1 < s.size() && s[j + 1] != '!') {
			j++;
			t += s[j];
			k += (s[j] == '[');
		}
		if (k > ans) {
			ans = k;
			anss = t;
		}
		i = j;
	}
	cout << max(0, ans) << endl << anss << endl;
	return 0;
}