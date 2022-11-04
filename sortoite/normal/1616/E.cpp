#include<bits/stdc++.h>
using namespace std;
const int NN = 1e5 + 10;
int n, b[NN];
vector<int> vec[26];
void add(int u, int d) {
	for(; u > 0; u -= u & - u) b[u] += d;
}
int calc(int u) {
	int ans = u;
	for(; u <= n; u += u & - u) ans += b[u];
	return ans;
}
char s[NN], t[NN];
void smin(long long & a, const long long & b) {
	if(a == -1 || (b != -1 && a > b)) a = b;
}
int main() {
#ifdef TRUE
	freopen("in.in", "r", stdin);
#endif
	int T; cin >> T;
	while(T --) {
		scanf("%d %s %s", &n, s + 1, t + 1);
		for(int i = n; i >= 1; i --) {
			vec[s[i] - 'a'].push_back(i);
			b[i] = 0;
		}
		long long ans = - 1, base = 0;
		for(int i = 1; i <= n; i ++) {
			for(int j = 0; 'a' + j < t[i]; j ++) {
				if(vec[j].size()) {
					smin(ans, base + calc(vec[j].back()) - i);
				}
			}
			if(vec[t[i] - 'a'].empty()) break;
			base += calc(vec[t[i] - 'a'].back()) - i;
			add(vec[t[i] - 'a'].back(), 1);
			vec[t[i] - 'a'].pop_back();
		}
		printf("%I64d\n", ans);
		for(int i = 0; i < 26; i ++) {
			vec[i].clear();
		}
	}
	return 0;
}