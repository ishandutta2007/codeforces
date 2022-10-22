#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int n;
struct node {
	int x, y;
} a[maxn];
char s[maxn];
int vis[maxn];
inline node sub(node x, node y) {
	return (node) {x.x - y.x, x.y - y.y};
}
inline ll cross(node x, node y) {
	return (ll) x.x * y.y - (ll) x.y * y.x;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	int now = 1;
	rep(i, 1, n) {
		cin >> a[i].x >> a[i].y;
		if(a[i].x < a[now].x || (a[i].x == a[now].x && a[i].y < a[now].y)) {
			now = i;
		}
	}
	cin >> s + 1;
	rep(i, 1, n) {
		vis[now] = 1;
		cout << now << ' ';
		int nxt = 0;
		const char type = s[i];
		rep(i, 1, n) if(!vis[i]) {
			a[i] = sub(a[i], a[now]);
			if(!nxt) {
				nxt = i;
			} else {
				if(type == 'R') {
					if(cross(a[i], a[nxt]) < 0) {
						nxt = i;
					}
				} else {
					if(cross(a[i], a[nxt]) > 0) {
						nxt = i;
					}
				}
			}
		}
		now = nxt;
	}
}