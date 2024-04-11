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

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld PI = 3.141592653589793238462643l;

vector<string> q;

int main() {
	//freopen("input.txt", "rt", stdin)
	//freopen("output.txt", "wt", stdout)
	int n;
	cin >> n;
	q.clear();
	forn (i, n) {
		string cmd;
		cin >> cmd;
		if (cmd == "pwd") {
			forn (i, q.size()) {
				cout << '/' << q[i];
			}
			cout << '/';
			cout << endl;
		} else {
			string adr;
			cin >> adr;
			int b = 0;
			if (adr[0] == '/') {
				q.clear();
				b = 1;
			}
			for (int i = b; i <= adr.size(); i++) {
				if (i == adr.size() || adr[i] == '/') {
					string f = adr.substr(b, i - b);
					if (f == "..") {
						q.pop_back();
					} else {
						q.pb(f);
					}
					b = i + 1;
				}
			}
		}
	}
	return 0;
}