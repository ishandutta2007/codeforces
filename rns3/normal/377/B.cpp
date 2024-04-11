#include <bits/stdc++.h>
using namespace std;

#define N 100010

int n, m, s, a[N], b[N], c[N], f[N], id[N], rmh[N], ans[N];


bool cmp(int i, int j) {
	return b[i] > b[j];
}

bool cmp1(int i, int j) {
	return a[i] < a[j];
}

int main() {
	scanf("%d %d %d", &n, &m, &s);
	for (int i = 1; i <= m; i ++) scanf("%d", &a[i]), rmh[i] = i;
	for (int i = 1; i <= n; i ++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i ++) scanf("%d", &c[i]), id[i] = i;
	sort (rmh + 1, rmh + m + 1, cmp1);
	sort (a + 1, a + m + 1);
	sort (id + 1, id + n + 1, cmp);
	bool tag = 0;
	for (int i = 1; i <= n && !tag; i ++) if(b[i] >= a[m] && c[i] <= s) tag = 1;
	if (tag) puts("YES");
	else {
		puts("NO");
		return 0;
	}
	priority_queue <int> Q;
    int st = 0, en = m, d;
    while (st < en - 1) {
		d = (st + en + 1) / 2;
		tag = 1;
		while (!Q.empty()) Q.pop();
		int tot = 0;
		for (int i = m, now = 1; i >= 1 && tag; i -= d) {
            while (now <= n && b[id[now]] >= a[i]) {
				Q.push(-c[id[now]]);
				now ++;
            }
            if (Q.empty()) tag = 0;
            else {
				tot -= Q.top();
				Q.pop();
				if (tot > s) tag = 0;
            }
		}
        if (tag) en = d;
        else st = d;
    }
    priority_queue<pair<int, int> > QQ;
    for (int i = m, now = 1; i >= 1; i -= en) {
        while (now <= n && b[id[now]] >= a[i]) {
			QQ.push(make_pair(-c[id[now]], id[now]));
            now ++;
        }
        pair <int, int> cur = QQ.top();
        QQ.pop();
		for (int j = i; j > max(0, i - en); j --) ans[rmh[j]] = cur.second;
    }
    for (int i = 1; i <= m; i ++) printf("%d ", ans[i]);
	return 0;
}