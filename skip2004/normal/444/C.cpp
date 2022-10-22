#include<bits/stdc++.h>
using std::cin;
using std::cout;
typedef long long ll;
const int maxn = 100100;
ll a[maxn], b[maxn];
inline void add(int l, int r, int v) {
	for(int i = l;i < maxn;i += i & -i) a[i] += v, b[i] += (ll) l * v;
	for(int i = r + 1;i < maxn;i += i & -i) a[i] -= v, b[i] -= (ll) (r + 1) * v;
}
inline ll ask(int l, int r) {
	ll ans = 0;
	for(int i = r;i;i &= i - 1) ans += (ll) (r + 1) * a[i] - b[i];
	for(int i = l - 1;i;i &= i - 1) ans -= (ll) l * a[i] - b[i];
	return ans;
}
std::map<int, int> map;
typedef std::pair<int, int> pr;
typedef std::map<int, int>::iterator iter;
inline iter split(int pos) {
	iter it = map.lower_bound(pos);
	if(it -> first == pos) return it;
	return --it, map.insert(it, pr(pos, it -> second));
}
inline void make(int l, int r, int v) {
	iter rt = split(r + 1), lt = split(l);
	for(iter i = lt;i != rt;) {
		iter nxt = i; ++ nxt;
		add(i -> first, nxt -> first - 1, std::abs(v - i -> second));
		i = nxt;
	}
	map.erase(lt, rt), map[l] = v;
}
int n, m;
int main(){ 
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n + 1;++i) map[i] = i;
	for(int i = 1;i <= m;++i) {
		int opt, l, r, v;
		cin >> opt;
		if(opt == 1) {
			cin >> l >> r >> v;
			make(l, r, v);
		} else {
			cin >> l >> r;
			cout << ask(l, r) << '\n';
		}
	}
}