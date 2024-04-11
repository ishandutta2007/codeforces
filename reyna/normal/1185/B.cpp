
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 1e5 + 5, mod = (int) 0;

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		string s, t;
		cin >> s >> t;
		int flag = 1, cnt = 0, pt = 0;
		for (int j = 0; j < (int) s.size(); ++j) {
			++cnt;
			if (j + 1 == (int) s.size() || s[j + 1] != s[j]) {
				int oc = 0;
				while (pt < (int) t.size() && s[j] == t[pt]) ++pt, ++oc;
				if (oc < cnt) {
					flag = 0;
					break;
				}
				cnt = 0;
			}
		}
		if (pt != (int) t.size()) flag = 0;
		if (!flag) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}