#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MX = 200005;
const int MN = 1000005;

struct Query {
	int st, en, id;
}q[MX], buf[MX];

bool operator < (Query A, Query B) {
	if (A.st != B.st) return A.st < B.st;
	return A.en < B.en;
}

bool cmp (Query A, Query B) {
	return A.en < B.en;
}

int n, Q;
int a[MX], cnt[MN];
LL ans[MX];

int main() {
	
	cin >> n >> Q;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 0; i < Q; i ++) {
		cin >> q[i].st >> q[i].en;
		q[i].id = i;
	}
	sort(q, q + Q);
	
	int Div = sqrt(n), curQ = 0;
	for (int per = 0; per <= n / Div; per ++) {
		//per * Div ~ (per + 1) * Div - 1
		int cn = 0;
		for (; curQ < Q; curQ ++) {
			if (q[curQ].st >= (per + 1) * Div) break;
			buf[cn ++] = q[curQ];
		}
		sort(buf, buf + cn, cmp);
		if (!cn) continue;
		//buf contains [per * Div, per * Div + Div) queries.
		
		for (int i = 1; i < MN; i ++) cnt[i] = 0;
		LL sum = 0;
		for (int i = buf[0].st; i <= buf[0].en; i ++) {
			cnt[a[i]] ++;
			sum += 1LL * cnt[a[i]] * cnt[a[i]] * a[i] - 1LL * (cnt[a[i]] - 1) * (cnt[a[i]] - 1) * a[i];
		}
		ans[buf[0].id] = sum;
		for (int i = 1; i < cn; i ++) {
			if (buf[i].st < buf[i - 1].st) {
				for (int j = buf[i].st; j < buf[i - 1].st; j ++) {
					cnt[a[j]] ++;
					sum += 1LL * cnt[a[j]] * cnt[a[j]] * a[j] - 1LL * (cnt[a[j]] - 1) * (cnt[a[j]] - 1) * a[j];
				}
			}
			else {
				for (int j = buf[i - 1].st; j < buf[i].st; j ++) {
					cnt[a[j]] --;
					sum += 1LL * cnt[a[j]] * cnt[a[j]] * a[j] - 1LL * (cnt[a[j]] + 1) * (cnt[a[j]] + 1) * a[j];
				}
			}
			for (int j = buf[i - 1].en + 1; j <= buf[i].en; j ++) {
				cnt[a[j]] ++;
				sum += 1LL * cnt[a[j]] * cnt[a[j]] * a[j] - 1LL * (cnt[a[j]] - 1) * (cnt[a[j]] - 1) * a[j];
			}
			ans[buf[i].id] = sum;
		}
	}
	for (int i = 0; i < Q; i ++) cout << ans[i] << endl;
}