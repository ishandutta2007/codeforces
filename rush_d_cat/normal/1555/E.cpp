#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000000 + 10;
struct Nod {
	int mn, lz;
} nod[N<<2];
void pushdown(int rt) {
	if (nod[rt].lz != 0) {
		nod[rt<<1].lz += nod[rt].lz;
		nod[rt<<1|1].lz += nod[rt].lz;
		nod[rt<<1].mn += nod[rt].lz;
		nod[rt<<1|1].mn += nod[rt].lz; 
		nod[rt].lz = 0;
	}
}
void update(int l,int r,int rt,int L,int R,int x) {
	if (L<=l && r<=R) {
		nod[rt].lz += x;
		nod[rt].mn += x;
		return;
	}
	int mid = (l+r)>>1; pushdown(rt);
	if (L<=mid) update(l,mid,rt<<1,L,R,x);
	if (R >mid) update(mid+1,r,rt<<1|1,L,R,x);
	nod[rt].mn = min(nod[rt<<1].mn, nod[rt<<1|1].mn);
}
int query(int l,int r,int rt,int L,int R) {
	if (L<=l&&r<=R) return nod[rt].mn;
	int mid=(l+r)>>1; pushdown(rt);
	int ans = 1e8;
	if(L<=mid) ans = min(ans, query(l,mid,rt<<1,L,R));
	if(R >mid) ans = min(ans, query(mid+1,r,rt<<1|1,L,R));
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector< vector<int> > seg;
	for (int i = 0; i < n; i ++) {
		vector<int> tmp(3);
		cin >> tmp[0] >> tmp[1] >> tmp[2]; tmp[1] --;
		seg.push_back(tmp);
	}
	sort(seg.begin(),seg.end(),[](vector<int>&a,vector<int>&b){
		return a[2] < b[2];
	});
	for (int i = 1; i <= 4 * m; i ++) nod[i].lz = 0, nod[i].mn = 0;
	int ans = 1e9;
	for (int i = 0, j = 0; i < n; i ++) {
		while (j < n && nod[1].mn == 0) {
			update(1,m-1,1,seg[j][0],seg[j][1],1); j ++;
		}
		if (nod[1].mn > 0) {
			ans = min(ans, seg[j-1][2] - seg[i][2]);
		}
		update(1,m-1,1, seg[i][0],seg[i][1],-1);
	}
	cout << ans << "\n";
}