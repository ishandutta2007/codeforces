#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 1010
int n, a[N];
int f[N];
string s[N];
set<PII> A;

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		s[i] = string(a[i], '0');
		A.insert(mp(-a[i], i));
		f[i] = i;
	}

	while ((int) A.size() >= 2) {
		PII x = *A.begin();
		A.erase(A.begin());
		PII y = *A.begin();
		A.erase(A.begin());
		int l = min(-x.fi, -y.fi)-1;
		if (l < 0) {
			puts ("NO");
			return 0;
		}
		
		for (int i = 0; i < n; i ++) 
			if (f[i] == y.se) {
				f[i] = x.se;
				s[i][l] = '1';
			}
		A.insert(mp(-l, x.se));
	}

	
	puts ("YES");
	for (int i = 0; i < n; i ++) {
		cout << s[i] << endl;
	}
	return 0;
}