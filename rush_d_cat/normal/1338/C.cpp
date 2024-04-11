#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
LL getD(LL totLen, LL pos) {
	if (totLen == 1) return 0;
	LL tmp = totLen, cnt = 1;
	while (tmp > 4) {
		tmp /= 4; cnt *= 4;
	}
	LL term = totLen / 4;
	if (pos <= term) return getD(term, pos);
	if (pos > term && pos <= 2*term) return getD(term, pos - term);
	if (pos > 2 * term && pos <= 3*term) return cnt + getD(term, pos - 2 * term);
	return cnt * 5 + getD(term, pos - 3*term);
}
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%lld",&n);
		LL id = (n - 1) / 3 + 1;
		LL start = 1, totLen = 1, sum = totLen, pos;
		while (sum < id) {
			start *= 4; totLen *= 4; sum += totLen;
		}
		pos = id - (sum - totLen);
		LL val = (start + (pos - 1)) * 2 - getD(totLen, pos);
		if (n % 3 == 1) {
			printf("%lld\n", start + pos - 1);
		} else if (n % 3 == 2) {
			printf("%lld\n", val);
		} else {
			printf("%lld\n", (start + pos - 1) ^ val);
		}
	}
	//printf("%lld, %lld, %lld\n", start, totLen, sum);

}