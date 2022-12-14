//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e5 + 9;
const int m = 60;
int arr[Maxn],n;
int t[4 * Maxn][m];
void build(int v = 1,int b = 0,int e = n-1) {
	if(b == e) {
		int x = arr[b];
		for(int i = 0; i < m;i++) {
			if(i % x == 0) t[v][i] = 2;
			else t[v][i] = 1;
		}
		return;
	}
	int mid = b + e >> 1,l = v << 1,r = l | 1;
	build(l,b,mid);
	build(r,mid+1,e);
	for(int i = 0; i < m;i++) {
		t[v][i] = t[l][i] + t[r][(t[l][i] + i) % m];
	}
}
void update(int idx,int x,int v = 1,int b = 0,int e = n-1) {
	if(b == e) {
		for(int i = 0; i < m;i++) {
			if(i % x == 0) t[v][i] = 2;
			else t[v][i] = 1;
		}
		return;
	}
	int mid = b + e >> 1 , l = v << 1,r = l | 1;
	if(mid + 1 > idx) {
		update(idx,x,l,b,mid);
	} else {
		update(idx,x,r,mid+1,e);
	}
	for(int i = 0; i < m;i++) {
		t[v][i] = t[l][i] + t[r][(t[l][i] + i) % m];
	}
	return;
}
int query(int i,int j,int ti = 0,int v = 1,int b = 0,int e = n-1) {
	if(i > e || b > j) return 0;
	if(i <= b && e <= j) {
	//	cout << b << ' ' << e << ' ' << ti << ' ' << t[v][ti] << '\n';
		return t[v][ti];
	}
	int mid = b + e >> 1,l = v << 1,r = l | 1;
	int fi = query(i,j,ti,l,b,mid);
	int se = query(i,j,(ti + fi) % m,r,mid+1,e);
	return fi + se;
}
int main() {
	scanf("%d",&n);
	for(int i = 0; i < n;i++) scanf("%d",&arr[i]);
	build();
	int q; scanf("%d",&q);
	while(q--) {
		char c; cin >> c;
		if(c == 'C') {
			int v,x; scanf("%d%d",&v,&x);
			update(--v,x);
		} else {
			int l,r; scanf("%d%d",&l,&r); l--,r--,r--;
			printf("%d\n",query(l,r));
		}
	}
	return 0;
}