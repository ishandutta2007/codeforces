//In the name of God
#include <bits/stdc++.h>
//Soalo ghablan hal kardam vali codesho dobare mizanam
using namespace std;
const int Maxn = 4e5 + 9;
typedef long long ll;
ll t[Maxn],sum[Maxn],arr[Maxn];
int n,m;
void build(int v = 1,int b = 0,int e = n-1){
	if(b == e){
		sum[v] = arr[b];
		t[v] = arr[b];
		return;
	}
	int mid = b + e >> 1 ,l = v << 1,r = l | 1;
	build(l,b,mid);
	build(r,mid+1,e);
	t[v] = max(t[l],t[r]);
	sum[v] = sum[l] + sum[r];
	return;
}
ll query(int i,int j,int v = 1,int b = 0,int e = n - 1){
	if(i > e || b > j) return 0;
	if(i <= b && e <= j) return sum[v];
	int mid = b + e >> 1,l = v << 1,r = l | 1;
	return query(i,j,l,b,mid) + query(i,j,r,mid+1,e);
}
void sing_upd(int idx,int x,int v = 1,int b = 0,int e = n - 1){
	if(b == e){
		t[v] = x;
		sum[v] = x;
		return;
	}
	int mid = b + e >> 1, l = v << 1,r = l | 1;
	if(idx < mid + 1) sing_upd(idx,x,l,b,mid);
	else sing_upd(idx,x,r,mid+1,e);
	t[v] = max(t[l],t[r]);
	sum[v] = sum[l] + sum[r];
}
void update(int i,int j,int x,int v = 1,int b = 0,int e = n-1){
	if(t[v] < x) return;
	if(i > e || b > j) return;
	if(b == e){
		t[v] %= x;
		sum[v] %= x;
		return;
	}
	int mid = b + e >> 1,l = v << 1,r = l | 1;
	update(i,j,x,l,b,mid);
	update(i,j,x,r,mid+1,e);
	t[v] = max(t[l],t[r]);
	sum[v] = sum[l] + sum[r];
	return;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < n;i++) cin >> arr[i];
	build();
	while(m--){
		int c;
		cin >> c;
		if(c == 1){
			int l,r;
			cin >> l >> r;
			--l,--r;
			cout << query(l,r) << '\n';
		}
		else if(c == 2){
			int l,r,x;
			cin >> l >> r >> x;
			update(--l,--r,x);
		}else{
			int v,x;
			cin >> v >> x;
			sing_upd(--v,x);
		}
	}
	return 0;
}