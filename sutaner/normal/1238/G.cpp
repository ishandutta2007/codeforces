#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define maxr 100000
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 600019
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    x = (f) ? x : -x;
}

int n, m, c, c0;

struct ele{
	int t, a, b;
	ele(int t, int a, int b) : t(t), a(a), b(b){}
	ele(){}
	bool operator < (const ele y) const{
		return (t == y.t) ? ((b == y.b) ? a > y.a : b < y.b) : t < y.t;
	}
};

ele lis[maxn];

multiset<pii> s;
ll nowc = 0;

inline void recover(){
	nowc = 0, s.clear();
}

int main(){
	int T, t, a, b;
	read(T);
	while (T--){
		read(n), read(m), read(c), read(c0);
		lis[0] = ele(0, c0, 0);
		rep(i, 1, n) read(t), read(a), read(b), lis[i] = ele(t, a, b);
		lis[++n] = ele(m, 0, 0);
		sort(lis, lis + 1 + n);
		ll ans = 0;
		rep(i, 0, n){
			int nowt = lis[i].t, nextt;
			while (i <= n && lis[i].t == nowt){
				nowc += lis[i].a;
				s.insert(pii(lis[i].b, lis[i].a));
				i++;
			}
			while (nowc > (ll)c){
				pii op = *s.rbegin(); s.erase(s.lower_bound(op));
				nowc -= op.se;
				if (nowc < c){
					op.se = c - nowc;
					s.insert(op);
					nowc += op.se;
					break;
				}
			}
			if (i <= n) {
				nextt = lis[i].t;
				int cost = nextt - nowt;
				while (!s.empty() && cost){
					pii op = *s.begin();
					s.erase(s.begin());
					if (cost < op.se) {
						ans += (ll)cost * op.fi;
						op.se -= cost;
						s.insert(op);
						nowc -= cost;
						cost = 0;
					}
					else {
						ans += (ll)op.fi * op.se;
						cost -= op.se;
						nowc -= op.se;
					}
				}
				if (cost) {
					printf("-1\n");
					goto jump;
				}
			}
			i--;
		}
		printf("%lld\n", ans);
		jump: recover();
	}
    return 0;
}