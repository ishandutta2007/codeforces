#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

int a[N];

int st[4 * N];

void update1(int idx, int l, int r, int s, int val){
	if(s < l || s > r){
		return;
	}
	if(l == r){
		st[idx] = val;
		return;
	}

	st[2 * idx] = max(st[idx], st[2 * idx]);
	st[2 * idx + 1] = max(st[idx], st[2 * idx + 1]);
	st[idx] = 0;

	int mid = (l + r) >> 1;

	update1(2 * idx, l, mid, s, val);
	update1(2 * idx + 1, mid + 1, r, s, val);
}

void update2(int idx, int l, int r, int sl, int sr, int val){
	if(sl > r || sr < l){
		return;
	}
	if(sl <= l && r <= sr){
		st[idx] = max(st[idx], val);
		return;
	}

	st[2 * idx] = max(st[idx], st[2 * idx]);
	st[2 * idx + 1] = max(st[idx], st[2 * idx + 1]);
	st[idx] = 0;

	int mid = (l + r) >> 1;

	update2(2 * idx, l, mid, sl, sr, val);
	update2(2 * idx + 1, mid + 1, r, sl, sr, val);
}

int query(int idx, int l, int r, int s){
	if(s < l || s > r){
		return 0;
	}
	if(l == r){
		return st[idx];
	}

	st[2 * idx] = max(st[idx], st[2 * idx]);
	st[2 * idx + 1] = max(st[idx], st[2 * idx + 1]);
	st[idx] = 0;

	int mid = (l + r) >> 1;

	return query(2 * idx, l, mid, s) + query(2 * idx + 1, mid +1, r, s);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;

	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> a[i];

		update1(1, 1, n, i, a[i]);
	}

	cin >> q;

	for(int i = 0; i < q; i++){
		int type;

		cin >> type;

		if(type == 1){
			int p, x;

			cin >> p >> x;

			update1(1, 1, n, p, x);
		}
		else{	
			int x;

			cin >> x;

			update2(1, 1, n, 1, n, x);
		}
	}

	for(int i = 1; i <= n; i++){
		cout << query(1, 1, n, i) << " ";
	}
	cout << "\n";

	return 0;
}