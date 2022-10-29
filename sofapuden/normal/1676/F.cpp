#include<bits/stdc++.h>

using namespace std;

int a, b, c, d, e;

void solve(){
	int n; cin >> n;
	int q; cin >> q;
	vector<int> v(n); for(auto &x : v)cin >> x;
	sort(v.begin(),v.end());
	int ls = -1;
	int cn = 1;
	int cu = -1;
	int st = 0;
	for(int i = 0; i < n; ++i){
		if(i && v[i]-v[i-1] > 1){
			cu = -1;
		}
		if(i != n-1 && v[i] == v[i+1]){cn++;continue;}
		if(cn >= q)cu++;
		else cu = -1;
		if(cu > ls){
			ls = cu;
			st = v[i];
		}
		cn = 1;
	}
	if(ls == -1){
		cout << -1 << '\n';
	}
	else{
		cout << st-ls << ' ' << st << '\n';

	}
}

int main(){

	int t; cin >> t;
	while(t--)solve();

}