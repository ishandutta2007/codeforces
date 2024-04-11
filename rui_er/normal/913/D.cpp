//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, T, L, R, ans, tag;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
struct Node {
	int a, t, id;
	Node(int a=0, int b=0, int c=0) : a(a), t(b), id(c) {}
	~Node() {}
	friend bool operator < (const Node &a, const Node &b) {
		if(a.t != b.t) return a.t < b.t;
		return a.a > b.a;
	}
}a[N];
bool check(int M) {
	int now = 0, tot = 0;
	rep(i, 1, n) {
		if(a[i].a < M) continue;
		if(now + a[i].t <= T) {
			now += a[i].t;
			if(++tot == M) return 1;
		}
		else break;
	}
	return 0;
}

int main() {
	scanf("%d%d", &n, &T);
	rep(i, 1, n) scanf("%d%d", &a[i].a, &a[i].t), a[i].id = i;
	sort(a+1, a+1+n);
	L = 0; R = n;
	while(R - L >= 5) {
		int M = (L + R) >> 1;
		if(check(M)) L = M + 1, ans = M;
		else R = M - 1;
	}
	per(i, R, L) {
		if(check(i)) {
			ans = i;
			printf("%d\n%d\n", ans, ans);
			int tot = 0;
			rep(j, 1, n) {
				if(a[j].a < i) continue;
				++tot; tag = 1;
				printf("%d%c", a[j].id, " \n"[tot==i]);
				if(tot == i) break;
			}
			break;
		}
	}
	if(!tag) {
		if(ans) {
			printf("%d\n%d\n", ans, ans);
			int tot = 0;
			rep(j, 1, n) {
				if(a[j].a < ans) continue;
				++tot; tag = 1;
				printf("%d%c", a[j].id, " \n"[tot==ans]);
				if(tot == ans) break;
			}
		}
		else puts("0\n0");
	}
    return 0;
}