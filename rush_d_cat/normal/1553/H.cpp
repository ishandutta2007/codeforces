#include <bits/stdc++.h>
using namespace std;

vector<int> genGray(int k) {
	if (k == 1) return vector<int>{0,1};
	vector<int> lef = genGray(k-1);
	vector<int> rig = lef; 
	reverse(rig.begin(), rig.end());
	for (auto x: rig) lef.emplace_back(x ^ (1<<(k-1)));
	return lef;
}
const int inf = 1e9;

struct Nod {
	bool is_swap;
	int len, mn, mx, ans;
	Nod(bool flag){
		len = 1;
		is_swap = false;
		ans = inf;
		if (flag) {
			mn = mx = 0;
		} else {
			mn = inf;
			mx = -inf;
		}
	}
	Nod() {}
	Nod operator + (const Nod &o) const {
		Nod nodRes;
		nodRes.len = len + o.len;
		nodRes.mn = min(mn, len + o.mn);
		nodRes.mx = max(mx, len + o.mx);
		nodRes.ans = min({ans, o.ans, o.mn + len - mx});
		return nodRes;
	}
	void prt() {
		printf("is_swap = %d, len = %d, mn = %d, mx = %d, ans = %d\n", 
			is_swap, len, mn, mx, ans);
	}
} nod[1<<20];

void pushup(int rt) {
	bool tmp = nod[rt].is_swap;
	if (nod[rt].is_swap == false) 
		nod[rt] = nod[rt<<1] + nod[rt<<1|1];
	else 
		nod[rt] = nod[rt<<1|1] + nod[rt<<1];
	nod[rt].is_swap = tmp;
}
bool vis[1<<20];
void build(int l, int r, int rt) {
	if (l == r) {
		nod[rt] = Nod(vis[l]); return;
	}
	int mid = (l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	nod[rt]=nod[rt<<1]+nod[rt<<1|1];
	nod[rt].is_swap = false;
	//printf("[%d,%d] ",l,r); nod[rt].prt();
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) 
		cin >> a[i], vis[a[i]] = 1;

	vector<int> gray = genGray(k);
	vector<int> ans(1<<k, 0);
	build(0, (1<<k) - 1, 1);
	ans[0] = nod[1].ans;

	for (int i = 1; i < 1<<k; i ++) {
		int bit = (int)log2(gray[i] ^ gray[i-1]);
		//printf("bit = %d\n", bit);

		for (int j = 1<<bit; j < 1<<(bit+1); j ++) 
			nod[j].is_swap ^= 1;
		
		for (int j = ((1<<(bit+1)) - 1); j >= 1; j --) 
			pushup(j);
		
		int pos = 0;
		for (int j = 0; j < k; j ++) if (gray[i] >> j & 1)
			pos |= (1<<(k-1-j));
		//printf("pos = %d, ans = %d\n", pos, nod[1].ans);
		ans[pos] = nod[1].ans;
	}
	for (int i = 0; i < 1<<k; i ++) 
		cout << ans[i] << " \n"[i==((1<<k)-1)];
}