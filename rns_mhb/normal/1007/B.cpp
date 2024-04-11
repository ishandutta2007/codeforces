#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define ep 1e-9
#define mp make_pair
#define pb push_back
#define ll long long
#pragma comment(linker, "/STACK:1024000000,1024000000")
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;
const double pi = 3.1415926535897932384626433832795028841971l;

#define N 100010

int d[N], t, a, b, c, ab, ac, bc, abc, q[10];

struct data{
	int x, y, z;
	bool operator == (const data &h) const{
		return x == h.x && y == h.y && z == h.z;
	}
	bool operator < (const data &h) const {
		if (x != h.x) return x < h.x;
		if (y != h.y) return y < h.y;
		return z < h.z;
	}
}f[100];

vector<int>u, v, w;

int main() {
	u.pb(1), u.pb(3), u.pb(5), u.pb(7);
	v.pb(2), v.pb(3), v.pb(6), v.pb(7);
	w.pb(4), w.pb(5), w.pb(6), w.pb(7);
	int tot = 0;
	for (int i = 0; i < 4; i ++) for (int j = 0; j < 4; j ++) for (int k = 0; k < 4; k ++) {
		vector<int> tmp;
		tmp.clear();
		tmp.pb(u[i]), tmp.pb(v[j]), tmp.pb(w[k]);
		sort(tmp.begin(), tmp.end());
		f[tot].x = tmp[0], f[tot].y = tmp[1], f[tot].z = tmp[2];
		tot ++;
	}
	sort(f, f + tot);
	tot = unique(f, f + tot) - f;
	for (int i = 1; i < N; i ++) for (int j = i; j < N; j += i) d[j] ++;
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d%d", &a, &b, &c);
		ab = __gcd(a, b), ac = __gcd(a, c), bc = __gcd(b, c);
		abc = __gcd(ab, c);
		q[1] = d[a], q[2] = d[b], q[4] = d[c], q[3] = d[ab], q[5] = d[ac], q[6] = d[bc], q[7] = d[abc];
		q[3] -= q[7], q[5] -= q[7], q[6] -= q[7];
		q[1] -= q[3] + q[5] + q[7], q[2] -= q[3] + q[6] + q[7], q[4] -= q[5] + q[6] + q[7];
		int ans = 0;
		for (int i = 0; i < tot; i ++) {
			if (f[i].x < f[i].y && f[i].y < f[i].z) ans += q[f[i].x] * q[f[i].y] * q[f[i].z];
			else if (f[i].x == f[i].y && f[i].y < f[i].z) ans += q[f[i].x] * (q[f[i].x] + 1) / 2 * q[f[i].z];
			else if (f[i].x < f[i].y) ans += q[f[i].x] * (q[f[i].y] + 1) * q[f[i].y] / 2;
			else ans += q[f[i].x] * (q[f[i].x] + 1) * (q[f[i].x] + 2) / 6;
		}
		cout<<ans<<endl;
	}
    return 0;
}