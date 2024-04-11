#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}
const int M = 5e5 + 10;

int n;
ll cur, lst;
struct pa {
    int d, a, id;
    pa() {}
    pa(int d, int a, int id) : d(d), a(a), id(id) {}
}p[M], q[M];
int f[60001];
int pn = 0, qn = 0;

inline bool cmp(pa a, pa b) {
    return a.d < b.d;
}
inline bool cmp2(pa a, pa b) {
    return a.a < b.a;
}

int main() {
    n = read(), cur = read(); lst = cur;
    for (int i = 1, D, A, C; i <= n; ++i) {
    	D = read(), C = read();
        A = C + D;
        lst += C;
        if(C >= 0) p[++pn] = pa{D, A, i};
        else q[++qn] = pa{D, A, i};
    }
    sort(p + 1, p + pn + 1, cmp);
    sort(q + 1, q + qn + 1, cmp2);
    int cnt = 0;
    for (int i = 1; i <= pn; ++i) {
        if(cur < p[i].d) break;
        else cur = cur - p[i].d + p[i].a;
        cnt++;
	} memset(f, -1, sizeof(f));
	f[cur] = 0;
	for(int i = qn; i >= 1; --i) {
		for(int j = 0; j <= cur; j++) if(f[j] != -1){
			if(j < q[i].d) continue;
			if(j - q[i].d + q[i].a < 0) continue;
			f[j - q[i].d + q[i].a] = max(f[j - q[i].d + q[i].a], f[j] + 1);
		}
	} int ans = 0;
	for(int j = 0; j <= cur; j++) ans = max(ans, f[j]);
	printf("%d\n", ans + cnt);
    return 0;
}