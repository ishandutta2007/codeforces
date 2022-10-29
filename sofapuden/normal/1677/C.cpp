#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool cmp(int &a, int &b){
	if((a^b)&1)return b&1;
	return a > b;
}

void solve(int testNum){
	int n; cin >> n;
	vector<int> A(n), B(n);
	vector<int> C(n), D(n);
	for(auto &x : A)cin >> x, x--;
	for(auto &x : B)cin >> x, x--;
	for(int i = 0; i < n; ++i){
		C[A[i]] = B[i];
		D[B[i]] = A[i];
	}
	vector<int> vis(n,0);
	vector<int> cy;
	for(int i = 0; i < n; ++i){
		if(vis[i])continue;
		int cn = 0;
		while(!vis[i]){
			vis[i] = 1;
			cn++;
			i = C[i];
		}
		cy.push_back(cn);
	}
	sort(cy.begin(),cy.end(),cmp);
	ll sz = n-1;
	ll ans = 0;
	for(int i = 0; i < (int)cy.size(); ++i){
		for(int j = 1; j < cy[i]; ++j){
			ans+=sz-j+1;
		}
		if(cy[i]&1)ans+=(cy[i])/2;
		else ans+=sz-(cy[i])/2+1;
		sz-=(cy[i]/2)*2;
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