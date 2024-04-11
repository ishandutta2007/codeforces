#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll m;
int a, b;

#define pii pair<int, int>
const int inf = 1000000010;
const int maxn = 300000;

int mneed[maxn+1]; //want the minimum needed to reach me

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> a >> b;
	int gc = __gcd(a, b);

	fill(mneed, mneed + maxn + 1, inf);
	mneed[0] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, 0));
	while (pq.size()) {
		pii vp = pq.top(); pq.pop();

		int sp = vp.second;
		int big = vp.first;

		// cout << sp << " -- " << big << endl;

		if (big != mneed[sp]) continue;

		if (sp >= b) {
			if (big < mneed[sp-b]) {
				mneed[sp-b] = big;
				pq.push(pii(big, sp-b));
			}

		}
		if (sp + a <= maxn) {
			if (max(big, sp+a) < mneed[sp+a]) {
				mneed[sp+a] = max(big, sp+a);
				pq.push(pii(mneed[sp+a], sp+a));
			}
		}
	}

	ll res = 0LL;
	for (int i = 0; i <= maxn; i++) {

		// if (i <= m) {
		// 	cout << i << " " << mneed[i] << endl;
		// }

		ll cadd = m - mneed[i]+1LL;
		if (cadd >= 0) res += cadd;
	}

	//now we look at all with gcd greater than or equal to maxn
	ll fi = 0LL;
	while (fi <= maxn) {
		fi += gc;
	}
	if (fi <= m) {
		ll nadd = m - fi+1LL;

		ll cv = nadd / gc;

		ll lo = nadd - cv * gc;

		//cv is also the count of guys - 1

		res += (nadd + lo) * (cv+1) /2LL;
	}

	cout << res << endl;

}