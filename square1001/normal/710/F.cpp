#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
const int lim = 300000;
const int mod1 = 1000000007;
const int mod2 = 1000000009;
int pw[2][300009], h[2][300009];
int main() {
	pw[0][0] = 1; pw[1][0] = 1;
	for(int i = 1; i <= lim; ++i) {
		pw[0][i] = 311LL * pw[0][i - 1] % mod1;
		pw[1][i] = 311LL * pw[1][i - 1] % mod2;
	}
	ios::sync_with_stdio(false);
	int q;
	cin >> q;
	map<int, int> sz;
	unordered_map<long long, int> d;
	for(int i = 0; i < q; ++i) {
		int tp; string str;
		cin >> tp >> str;
		long long hv = 0;
		if(tp != 3) {
			int va = 0, vb = 0;
			for(int i = 0; i < str.size(); ++i) {
				va = (311LL * va + str[i]) % mod1;
				vb = (311LL * vb + str[i]) % mod2;
			}
			hv = 1LL * va * mod2 + vb;
		}
		if(tp == 1) {
			++sz[str.size()];
			++d[hv];
		}
		if(tp == 2) {
			if(--sz[str.size()] == 0) {
				sz.erase(str.size());
			}
			--d[hv];
		}
		if(tp == 3) {
			for(int i = 0; i < str.size(); ++i) {
				h[0][i + 1] = (311LL * h[0][i] + str[i]) % mod1;
				h[1][i + 1] = (311LL * h[1][i] + str[i]) % mod2;
			}
			long long ans = 0;
			for(pair<int, int> i : sz) {
				int len = i.first;
				if(len > str.size()) break;
				for(int j = 0; j <= str.size() - len; ++j) {
					int v1 = h[0][j + len] - 1LL * h[0][j] * pw[0][len] % mod1; if(v1 < 0) v1 += mod1;
					int v2 = h[1][j + len] - 1LL * h[1][j] * pw[1][len] % mod2; if(v2 < 0) v2 += mod2;
					ans += d[1LL * v1 * mod2 + v2];
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}