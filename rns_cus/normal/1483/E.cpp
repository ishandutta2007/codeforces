#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[20];
const ll M = 1e14;

int query(ll x) {
	printf("? %lld\n", x);
	fflush(stdout);
	scanf("%s", s);
	if (s[0] == 'L') return 1;
	if (s[1] == 'r') return 0;
	exit(1);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
		ll cur = 1;
		if (query(cur)) cur <<= 1;
		else {
			printf("! 0\n"); fflush(stdout);
			continue;
		}
		if (query(cur)) cur <<= 1;
		else {
			printf("! 1\n"); fflush(stdout);
			continue;
		}
		ll dn = 2, up;
		while (1) {
			ll prv = cur;
			if (prv > M) {
				up = M + 1; break;
			}
			if (query(prv)) dn = prv, cur += prv;
			else {
				up = prv, cur -= prv;
				break;
			}
		}
		int cnt = 0;
		while (up - dn > 1) {
			double d = 1.0 / 3 + cnt / 50.0;
			d = min(d, 1.0);
			ll mi = (dn + up * d) / (1 + d);
			if (mi == dn) mi ++;
			while (cur < mi) query(dn), cur += dn, cnt ++;
			if (query(mi)) cur += mi, dn = mi, cnt ++;
			else cur -= mi, up = mi, cnt --;
		}
		printf("! %lld\n", dn); fflush(stdout);
    }

    return 0;
}