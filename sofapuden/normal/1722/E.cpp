#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	vector<vector<ll>> gr(1005, vector<ll>(1005,0));
	int n, q; cin >> n >> q;
	for(int i = 0; i < n; ++i){
		ll a, b; cin >> a >> b;
		gr[a][b] += a*b;
	}
	for(int i = 1; i < 1005; ++i){
		for(int j = 1; j < 1005; ++j){
			gr[i][j]+=gr[i-1][j];
			gr[i][j]+=gr[i][j-1];
			gr[i][j]-=gr[i-1][j-1];
		}
	}
	for(int i = 0; i < q; ++i){
		int a, b, c, d; cin >> a >> b >> c >> d;
		cout << gr[c-1][d-1] + gr[a][b] - gr[c-1][b] - gr[a][d-1] << '\n';
	}
}

int main(){
	int t; cin >> t;
	while(t--)solve();

}