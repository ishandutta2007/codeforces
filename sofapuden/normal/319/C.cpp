#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mx = (1ll<<60);

vector<pair<ll,ll>> v;

struct Line{
	ll a, b;
	Line(ll _a, ll _b) : a(_a), b(_b) {}

	ll eval(ll x){
		return a*x + b;
	}
};

struct LCT{
	int n;
	vector<Line> st;
	LCT(int sz) : n(sz), st(4*n, Line(0, mx)) {}

	void ins(Line f, int p = 1, int l = 0, int r = -2){
		if(r == -2)r = n-1;
		if(l > r)return;
		int m = (l+r)>>1;
		bool lf = f.eval(v[l].first) < st[p].eval(v[l].first);
		bool mf = f.eval(v[m].first) < st[p].eval(v[m].first);
		if(mf){
			swap(st[p],f);
		}
		if(lf == mf){
			ins(f,p*2+1,m+1,r);
		}else{
			ins(f,p*2,l,m-1);
		}
	}
	ll que(int x, int p = 1, int l = 0, int r = -2){
		if(r == -2)r = n-1;
		if(l > r)return mx;
		int m = (l+r)>>1;
		if(v[m].first > x)return min(st[p].eval(x),que(x,p*2,l,m-1));
		return min(st[p].eval(x),que(x,p*2+1,m+1,r));
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(auto &x : a)cin >> x;
	for(auto &x : b)cin >> x;
	for(int i = 0; i < n; ++i){
		v.push_back({a[i],b[i]});
	}
	LCT lct(n);
	vector<ll> dp(n,0);
	lct.ins(Line(v[0].second,0));
	for(int i = 1; i < n; ++i){
		dp[i] = lct.que(v[i].first);
		lct.ins(Line(v[i].second,dp[i]));
	}
	cout << dp.back() << '\n';

}