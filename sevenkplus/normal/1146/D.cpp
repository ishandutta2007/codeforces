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

#define INF 1000000007
#define N 200010
int m, a, b;
int d[N];
int s[N];

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int main() {
	cin >> m >> a >> b;
	m++;
	for (int i = 1; i < a+b; i ++) d[i] = INF;
	set<PII> q;
	q.insert(mp(0, 0));
	while (!q.empty()) {
		int x = q.begin()->se;
		q.erase(q.begin());
		if (x >= b) {
			if (d[x-b] > d[x]) {
				q.erase(mp(d[x-b], x-b));
				d[x-b] = d[x];
				q.insert(mp(d[x-b], x-b));
			}
		}
		if (x+a < a+b) {
			if (d[x+a] > max(d[x], x+a)) {
				q.erase(mp(d[x+a], x+a));
				d[x+a] = max(d[x], x+a);
				q.insert(mp(d[x+a], x+a));
			}
		}
	}
	for (int i = 0; i < a+b; i ++)
		if (d[i] < INF) s[d[i]] ++;
	for (int i = 0; i < a+b; i ++) s[i+1] += s[i];
	ll S = 0;
	for (int i = 0; i < min(m, a+b); i ++) S += s[i];
	if (a+b < m) {
		int g = gcd(a, b);
		int le = a+b, ri = m-m%g;
		S += (ll)(ri-le) * (le/g + ri/g +1)/2;
		S += m%g * (m/g+1);
	}
	cout << S << endl;
	return 0;
}