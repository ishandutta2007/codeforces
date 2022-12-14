//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn = 4e5 + 9;
const int lg = 20;
ll t[Maxn],exor[Maxn][lg],change[Maxn],arr[Maxn],n,q;
void build(int v = 1,int b = 0,int e = n-1){
	if(b == e){
		for(int i = 0; i < lg ;i++)
			if(arr[b] >> i & 1)
				exor[v][i]++;
		t[v] = arr[b];
		return;
	}
	int mid = b + e >> 1,l = v << 1,r = l | 1;
	build(l,b,mid);
	build(r,mid+1,e);
	t[v] = t[l] + t[r];
	for(int i = 0; i < lg;i++)
		exor[v][i] = exor[l][i] + exor[r][i];
	return;
}
void upd(int v,int sz,int x){
	for(int i = 0; i < lg;i++)
		if(x >> i & 1){
			t[v] += (sz - 2 * exor[v][i]) * (1 << i);
			exor[v][i] = sz - exor[v][i];
		}
	return;
}
void prop(int v,int l,int r,int sz1,int sz2){
	upd(l,sz1,change[v]);
	upd(r,sz2,change[v]);
	change[l] ^= change[v];
	change[r] ^= change[v];
	change[v] = 0;
	return;
}
ll query(int i,int j,int v = 1,int b = 0,int e = n-1){
	if(i > e || b > j) return 0;
	if(i <= b && e <= j) return t[v];
	int mid = b + e >> 1,l = v << 1,r = l | 1,sz1 = mid - b + 1,sz2 = e - mid;
	prop(v,l,r,sz1,sz2);
	return query(i,j,l,b,mid) + query(i,j,r,mid+1,e);
}
void update(int i,int j,int x,int v = 1,int b = 0,int e = n-1){
	if(i > e || b > j) return;
	if(i <= b && e <= j){
		upd(v,e-b+1,x);
		change[v] ^= x;
		return;
	}
	int mid = b + e >> 1,l = v << 1,r = l | 1,sz1 = mid - b + 1,sz2 = e - mid;
	prop(v,l,r,sz1,sz2);
	update(i,j,x,l,b,mid);
	update(i,j,x,r,mid+1,e);
	t[v] = t[l] + t[r];
	for(int k = 0; k < lg;k++)
		exor[v][k] = exor[l][k] + exor[r][k];
	return;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n;i++) cin >> arr[i];
	build();
	cin >> q;
	while(q--){
		int c,l,r,x;
		cin >> c >> l >> r;
		--l,--r;
		if(c == 1){
			cout << query(l,r) << '\n';
		}else{
			cin >> x;
			update(l,r,x);
		}
	}
	return 0;
}