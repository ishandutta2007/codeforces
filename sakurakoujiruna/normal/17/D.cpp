#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = (int)1e6 + 11;
char sb[N], sn[N];

int main() {
	scanf("%s%s", sb, sn);
	ll mod; cin >> mod;
	int lb = strlen(sb), ln = strlen(sn);

	ll b = 0;
	for(int i = 0; i < lb; i ++)
		b = (b * 10 + sb[i] - '0') % mod;

	for(int i = ln - 1; i >= 0; i --) if(sn[i] != '0') {
		sn[i] --;
		for(int j = i + 1; j < ln; j ++)
			sn[j] = '9';
		break;
	}
	ll r = 1, now = b;
	for(int i = ln - 1; i >= 0; i --) {
		ll nxt = 1;
		for(int j = 1; j <= 10; j ++) {
			nxt = nxt * now % mod;
			if(j == sn[i] - '0')
				r = r * nxt % mod;
		}
		now = nxt;
	}
	r = (r * (b - 1) % mod + mod) % mod;
	if(r == 0) r = mod;
	cout << r << '\n';
	return 0;
}