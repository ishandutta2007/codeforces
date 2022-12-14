//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5 + 9;
int t[3 * Maxn],dif[3 * Maxn],change[3 * Maxn];
int st[Maxn],ft[Maxn],h[Maxn];
int val[Maxn],arr[Maxn],ts;
int n,q;
vector<int> al[Maxn];
void dfs(int v = 0,int p = -1){
	h[v] = (v ? h[p] + 1 : 0);
	st[v] = ts;
	arr[ts++] = v;
	for(int i = 0; i < al[v].size();i++){
		int u = al[v][i];
		if(u == p) continue;
		dfs(u,v);
	}
	ft[v] = ts;
}
void build(int v = 1,int b = 0,int e = n-1){
	if(b == e){
		t[v] = val[arr[b]];
		dif[v] = (h[arr[b]] & 1 ? -1 : 1);
		change[v] = 0;
		return;
	}
	int mid = b + e >> 1,l = v << 1,r = l | 1;
	build(l,b,mid);
	build(r,mid+1,e);
	t[v] = t[l] + t[r];
	dif[v] = dif[l] + dif[r];
	return;
}
void prop(int v,int l,int r){
	t[l] += change[v] * dif[l];
	t[r] += change[v] * dif[r];
	change[l] += change[v];
	change[r] += change[v];
	change[v] = 0;
	return;
}
void update(int i,int j,int x,int v = 1,int b = 0,int e = n-1){
	if(i > e || b > j) return;
	if(i <= b && e <= j){
		change[v] += x;
		t[v] += x * dif[v];
		return;
	}
	int mid = b + e >> 1,l = v << 1,r = l | 1;
	prop(v,l,r);
	update(i,j,x,l,b,mid);
	update(i,j,x,r,mid+1,e);
	t[v] = t[l] + t[r];
	return;
}
int query(int i,int j,int v = 1,int b = 0,int e = n-1){
	if(i > e || b > j) return 0;
	if(i <= b && e <= j) return t[v];
	int mid = b + e >> 1,l = v << 1,r = l | 1;
	prop(v,l,r);
	return query(i,j,l,b,mid) + query(i,j,r,mid+1,e);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin >> n >> q;
	for(int i = 0; i < n;i++) cin >> val[i];
	for(int i = 0; i < n-1;i++){
		int u,v;
		cin >> u >> v;
		al[--u].push_back(--v);
		al[v].push_back(u);
	}
	dfs();
	build();
	while(q--){
		int c;
		cin >> c;
		if(c == 2){
			int v;
			cin >> v;
			--v;
			cout << query(st[v],st[v]) << '\n';
		}else{
			int v,x;
			cin >> v >> x;
			--v;
			update(st[v],ft[v] - 1,(h[v] & 1 ? -x : x));
		}
	}
	return 0;
}