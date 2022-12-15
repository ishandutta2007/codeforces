#include <bits/stdc++.h>

using namespace std;

struct SegmentTree{
	vector<int> tr, lz;
	int n;

	SegmentTree(int n = 0){
		this->n = n;
		tr.resize(4 * n);
		lz.resize(4 * n);
	}

	void update_lazy(int idx, int l, int r){
		if(!lz[idx])
			return;

		tr[idx] += lz[idx];
		if(l != r){
			lz[2 * idx] += lz[idx];
			lz[2 * idx + 1] += lz[idx];
		}
		lz[idx] = 0;
	}

	void update(int idx, int l, int r, int sl, int sr, int diff){
		update_lazy(idx, l, r);
		if(l > sr || sl > r)
			return;
		if(sl <= l && r <= sr){
			lz[idx] += diff;
			update_lazy(idx, l, r);
			return;
		}

		int mid = (l + r) >> 1;
		update(2 * idx, l, mid, sl, sr, diff);
		update(2 * idx + 1, mid + 1, r, sl, sr, diff);

		tr[idx] = max(tr[2 * idx], tr[2 * idx + 1]);
	}

	int query(int idx, int l, int r, int sl, int sr){
		update_lazy(idx, l, r);
		if(l > sr || sl > r)
			return 0;
		if(sl <= l && r <= sr)
			return tr[idx];

		int mid = (l + r) >> 1;
		int a = query(2 * idx, l, mid, sl, sr);
		int b = query(2 * idx + 1, mid + 1, r, sl, sr);

		return max(a, b);
	}
};

const int kN = 3e5 + 7;

int p[kN], q[kN], n, pos[kN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> p[i];
		pos[p[i]] = i;
	}
	for(int i = 1; i <= n; ++i)
		cin >> q[i];

	SegmentTree seg_tr(n);
	int ans = n;
	seg_tr.update(1, 1, n, 1, pos[ans], 1);
	for(int i = 1; i <= n; ++i){
		while(ans > 1 && seg_tr.query(1, 1, n, 1, n) <= 0){
			--ans;
			seg_tr.update(1, 1, n, 1, pos[ans], 1);
		}
		seg_tr.update(1, 1, n, 1, q[i], -1);
		cout << ans << " ";
	}
	cout << "\n";
}