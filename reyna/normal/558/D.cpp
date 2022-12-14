//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int H = 155;
const int N = 1e5 + 9;
int l[N * H],r[N * H],t[N * H],ch[N * H];
ll nxt = 1,h,q;
ll f,s;
void extend(int v) {
	l[v] = nxt++;
	r[v] = nxt++;
}
void prop(int v) {
	t[l[v]] += ch[v];
	t[r[v]] += ch[v];
	ch[l[v]] += ch[v];
	ch[r[v]] += ch[v];
	ch[v] = 0;
	return;
}
void update(ll i,ll j,int v = 0,ll b = f,ll e = s) {
	if(i > e || b > j) return;
	if(i <= b && e <= j) {
		t[v]++;
		ch[v]++;
		return;
	}
	if(l[v] == -1) extend(v);
	ll mid = b + e >> 1;
	prop(v);
	update(i,j,l[v],b,mid);
	update(i,j,r[v],mid+1,e);
	t[v] = max(t[l[v]],t[r[v]]);
	return;
}
void find(int v = 0,ll b = f,ll e = s) {
	if(l[v] == -1) extend(v);
	ll mid = b + e >> 1;
	prop(v);
	if(b == e) {
		cout << b << '\n';
		exit(0);
	}
	if(t[l[v]] == q && t[r[v]] == q) {
		cout << "Data not sufficient!\n";
		exit(0);
	}
	if(t[l[v]] != q && t[r[v]] != q) {
		cout << "Game cheated!\n";
		exit(0);
	}
	if(t[l[v]] == q) find(l[v],b,mid);
	else find(r[v],mid+1,e);
	return;
}
main() {
	ios_base::sync_with_stdio(0);
	memset(l,-1,sizeof l);
	memset(r,-1,sizeof r);
	cin >> h >> q;
	f = 1LL << (h - 1),s = (1LL << h) - 1;
	for(int k = 0; k < q; ++k) {
		ll i,L,R,ans; cin >> i >> L >> R >> ans; L *= 1LL << (h - i),R *= (1LL << (h - i)), R += (1LL << (h - i)) - 1;
		if(ans == 0) {
			update(f,L - 1);
			update(R+1,s);
		} else {
			update(L,R);
		}
	}
	if(t[0] != q) {
		cout << "Game cheated!\n";
		return 0;
	}
	find();
}