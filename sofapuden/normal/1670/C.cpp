#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int uf(int x, vector<int> &ufa){
	return ufa[x] = x^ufa[x] ? uf(ufa[x],ufa) : x;
}

void solve(int testID){
	int n; cin >> n;
	vector<int> a(n), b(n), c(n);
	for(auto &x : a)cin >> x;
	for(auto &x : b)cin >> x;
	for(auto &x : c)cin >> x;
	ll ans = 1;
	vector<int> ufa(n+1);
	vector<int> don(n+1,0);
	iota(ufa.begin(),ufa.end(),0);
	for(int i = 0; i < n; ++i){
		int A = uf(a[i],ufa), B = uf(b[i],ufa);
		ufa[A] = B;
		if(a[i] == b[i])don[a[i]] = 1;
	}
	for(int i = 0; i < n; ++i){
		if(!c[i])continue;
		don[uf(c[i],ufa)] = 1;
	}
	for(int i = 1; i <= n; ++i){
		ans *= (don[uf(i,ufa)]^1)+1;
		ans%=(ll)1e9+7;
		don[uf(i,ufa)] = 1;
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	int cn = 1;
	while(t--){
		solve(cn++);

	}

}