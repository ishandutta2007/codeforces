#include <bits/stdc++.h>

using namespace std;

#define maxn 100010
#define ll long long

int p[maxn];
bool seen[maxn];
// int goal;
int ct;
void rec(int u) {
	// cout << "u  " << u << endl;
	if (seen[u]) return;
	seen[u] = true;
	ct++;
	rec(p[u]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i  = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
		seen[i] = false;
	}
	ll ans = 0LL;
	vector<int> cycs;
	for (int i = 0; i < n; i++) {
		if (!seen[i]) {
			ct = 0;
			rec(i);
			cycs.push_back(ct);
			ans += ((ct+0LL)*(ct-0LL));
		}
	}
	sort(cycs.begin(), cycs.end());
	reverse(cycs.begin(), cycs.end());
	if (cycs.size() > 1) {
		ll o1 = cycs[0];
		ll o2 = cycs[1];
		ans -= (o1*(o1));
		ans -= (o2*(o2));
		ans += ((o1+o2)*(o1+o2));
	}
	cout << ans << endl;
	cin >> n;
	
}