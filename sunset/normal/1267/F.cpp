#include <bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define db double
#define mod 998244353
#define maxn 200005
using namespace std;
ll ksm(ll a, ll b) {
	if (!b) return 1;
	ll ns = ksm(a, b >> 1);
	ns = ns * ns % mod;
	if (b & 1) ns = ns * a % mod;
	return ns;
}
pi eg[maxn];
set<int> id;
int cnt[maxn];
vi s[2];
int main() {
	int n, m, ka, kb;
	cin >> n >> m >> ka >> kb;
	if (ka > m - 1) {
		printf("No\n");
		return 0;
	}
	if (kb > n - 1) {
		printf("No\n");
		return 0;
	}
	s[0].resize(ka), s[1].resize(kb);
	int pl[2] = {0, 0};
	for (int i = 0; i < ka; i++)
		scanf("%d", &s[0][i]), cnt[s[0][i]]++;
	for (int i = 0; i < kb; i++)
		scanf("%d", &s[1][i]), cnt[s[1][i]]++;
	while (s[0].size() < m - 1) 
		s[0].pb(1), cnt[1]++;
	while (s[1].size() < n - 1)
		s[1].pb(n + 1), cnt[n + 1]++;
	
	for (int i = 1; i <= n + m; i++)
		if (!cnt[i]) id.insert(i);
	cout << "Yes" << endl;
	for (int i = 0; i < n + m - 1; i++) {
 		if (i == n + m - 2) {
 			cout << *id.begin() << ' ' << *(--id.end()) << endl;
 			break;
 		}
		int x = *id.begin();
		id.erase(x);
		if (x <= n) {
			int nid = s[1][pl[1]];
			printf("%d %d\n", x, nid);
			cnt[nid]--;
			if (!cnt[nid]) id.insert(nid);
			pl[1]++;
		}
		else {
			int nid = s[0][pl[0]];
			printf("%d %d\n", x, nid);
			cnt[nid]--;
			if (!cnt[nid]) id.insert(nid);
			pl[0]++;
		}
	}
	return 0;
}
/*
4 5 4 2
1 3 3 4
7 8

4 3 3 1
3 2 2
6

*/