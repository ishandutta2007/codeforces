#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	int n; cin >> n;
	vector<int> X(n);
	vector<int> T(n);
	for(auto &x : X)cin >> x; 
	for(auto &x : T)cin >> x; 
	double l = 0, r = 1e8, bes = 0;
	while(r-l > 1e-7){
		double d1 = (r+l+l)/3, d2 = (r+r+l)/3;
		double a1 = 0, a2 = 0;
		for(int i = 0; i < n; ++i){
			a1 = max(a1,abs(d1-X[i])+T[i]);
			a2 = max(a2,abs(d2-X[i])+T[i]);
		}
		if(a1 > a2){
			bes = d2;
			l = d1;
		}
		else{
			bes = d1;
			r = d2;
		}
	}
	printf("%.7f\n",bes);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();
}