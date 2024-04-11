#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 5e3+5;

int an1[mxN][mxN], an2[mxN][mxN];

void solve(int testNum){
	int n; cin >> n;
	vector<ll> v(n);
	for(auto &x : v)cin >> x;
	for(int i = 0; i < n; ++i){
		ll am1 = 0;
		for(int j = n-1; ~j; --j){
			an1[i][j] = am1;
			if(v[j] < v[i])am1++;
		}
	}
	ll ans = 0;
	for(int i = 0; i < n; ++i){
		ll am2 = 0;
		for(ll j = 0; j < n; ++j){
			an2[i][j] = am2;
			if(v[j] < v[i])am2++;
		}
	}
	for(ll i = 0; i < n; ++i){
		for(ll j = i+1; j < n; ++j){
			ans+=1ll*an1[i][j]*an2[j][i];

		}
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	//solve(0);return 0;
	int t; cin >> t;
	int cn = 1;
	while(t--){
		solve(cn++);
	}
}