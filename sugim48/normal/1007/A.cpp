#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;

int main() {
	int N; cin >> N;
	map<int, int> mp;
	rep(i, N) {
		int x; scanf("%d", &x);
		mp[x]++;
	}
	int rest = 0, ans = 0;
	for (i_i z: mp) {
		int x = z.second;
		int k = min(x, rest);
		rest -= k, ans += k;
		rest += x;
	}
	cout << ans << endl;
}