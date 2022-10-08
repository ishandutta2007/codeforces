#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int n, m;
set<string> A;
int un, um, up;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i ++) {
		string s;
		cin >> s;
		A.insert(s);
	}
	un = n;
	um = m;
	up = 0;
	for (int i = 0; i < m; i ++) {
		string s;
		cin >> s;
		if (A.find(s) != A.end()) {
			un --;
			um --;
			up ++;
		}
	}
	int t = 0;
	while (true) {
		if (t == 0) {
			if (un+up == 0) {
				puts ("NO");
				break;
			}
			if (up) up--; else un--;
		} else {
			if (um+up == 0) {
				puts ("YES");
				break;
			}
			if (up) up--; else um--;
		}
		t ^= 1;
	}
	return 0;
}