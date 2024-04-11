#include <bits/stdc++.h>
using namespace std;

#define N 1000010
#define M 100010

char s[N];
int n, m, sta[N], id[M], fen[N], ans[M];

typedef pair <int, int> pii;

pii p[N], q[M];

bool cmp(int a, int b) {
	return q[a] < q[b];
}

int main() {
	gets(s + 1);
	n = strlen(s + 1);
	scanf("%d", &m);
	for (int i = 1; i <= m; i ++) scanf("%d %d", &q[i].second, &q[i].first), id[i] = i;
	sort (id + 1, id + m + 1, cmp);
	sort (q + 1, q + m + 1);
	int cnt = 0, e = 0;
    for (int i = 1; i <= n; i ++) {
    	if (s[i] == '(') sta[++e] = i;
		else if (e) {
			p[++cnt] = make_pair(i, sta[e--]);
		}
    }
    sort (p + 1, p + cnt + 1);
    for (int en = 1, now = 1, cur = 1; en <= n; en ++) {
        while (now <= cnt && p[now].first == en) {
            for (int i = p[now].second; i < N; i += i & -i) fen[i] ++;
			now ++;
        }
        while (cur <= m && q[cur].first == en) {
        	int rlt = 0;
        	for (int i = en; i; i -= i & -i) rlt += fen[i];
        	for (int i = q[cur].second - 1; i; i -= i & -i) rlt -= fen[i];
        	ans[id[cur]] = rlt;
            cur ++;
        }
    }
    for (int i = 1; i <= m; i ++) printf("%d\n", 2 * ans[i]);
	return 0;
}