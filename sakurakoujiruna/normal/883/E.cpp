#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

int n, m;
char s[56];
char a[1006][56];

bitset<26> use, sol;

bool check(char *a) {
	for (int i = 0; i < n; ++i) if (s[i] != '*')
		if (a[i] != s[i])
			return false;
	
	for (int i = 0; i < n; ++i) if (s[i] == '*')
		if (use[a[i] - 'a'])
			return false;
	
	return true;
}

int main() {
	cin >> n;
	scanf("%s", s);
	
	for (int i = 0; i < n; ++i) if (s[i] != '*')
		use.set(s[i] - 'a');
	
	cin >> m;
	for (int i = 0; i < m; ++i)
		scanf("%s", a[i]);
	
	sol.set();
	
	for (int i = 0; i < m; ++i) {
		if (check(a[i])) {
			bitset<26> t;
			for (int j = 0; j < n; ++j) if (s[j] == '*')
				t.set(a[i][j] - 'a');
			sol &= t;
		}
	}
	
	cout << sol.count() << endl;
	
	return 0;
}