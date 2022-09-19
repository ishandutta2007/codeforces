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

const ld pi = 3.141592653589793238462643l;

vector<string> ans;

int main () {
#ifdef LOCAL
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	string s, t;
	getline(cin, s);
	s += ' ';
	forn (i, s.size()) {
		if (s[i] == '"') {
			int j = i + 1;
			while (s[j] != '"') {
				j++;
			}
			ans.pb(s.substr(i + 1, j - i - 1));
			i = j;
			continue;
		}
		if (s[i] == ' ') {
			if (t.size()) {
				ans.pb(t);
				t = "";
			}
			continue;
		}
		t += s[i];
	}
	forn (i, ans.size()) {
		cout << '<' << ans[i] << '>' << endl;
	}
	return 0;
}