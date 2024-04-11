#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define N 500050

priority_queue <LL, vector <LL>, greater<LL> > Qa;
priority_queue <LL> Qb;

LL a[N], b[N];
int n, m;

const LL INF = 1e13;

int main() {
//	freopen("in.txt", "r", stdin);

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i ++) scanf("%I64d", a + i);
	for (int i = 1; i <= n; i ++) scanf("%I64d", b + i);

	LL st = 0, en = INF, ans = 0;

	while (st <= en ) {
		LL mid = (st + en) >> 1;
		while ( !Qa.empty() ) Qa.pop();
		while ( !Qb.empty() ) Qb.pop();
		LL tmp = 0;
		int sz = 0;
		for (int i = 1; i <= n; i ++) {
			Qa.push(a[i]);
			LL tmp1 = Qa.top() + b[i] - mid;
			LL tmp2 = Qb.empty() ? INF : b[i] - Qb.top();
			if (tmp1 <= tmp2 && tmp1 <= 0) {
				tmp += tmp1; sz ++;
				Qb.push(b[i]);
				Qa.pop();
			}
			else if (tmp2 < tmp1 && tmp2 < 0){
				tmp += tmp2;
				Qb.pop();
				Qb.push(b[i]);
			}
		}

		if (sz >= m) {
			ans = tmp + m * mid;
			en = mid - 1;
		}
		else {
			st = mid + 1;
		}
	}

	cout << ans << endl;
}