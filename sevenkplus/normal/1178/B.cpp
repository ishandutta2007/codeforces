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

#define N 1000010
string s;
int n;
int pr[N], ne[N];

int main() {
	cin >> s;
	n = (int) s.size();
	pr[0] = 0;
	for (int i = 1; i < n; i ++)
		pr[i] = pr[i-1] + (s[i] == 'v' && s[i-1] == 'v');
	ne[n-1] = 0;
	for (int i = n-1; i >= 0; i--)
		ne[i] = ne[i+1] + (s[i] == 'v' && s[i+1] == 'v');
	ll S = 0;
	for (int i = 0; i < n; i ++)
		if (s[i] == 'o')
			S += (ll) pr[i] * ne[i];
	cout << S << endl;
	return 0;
}