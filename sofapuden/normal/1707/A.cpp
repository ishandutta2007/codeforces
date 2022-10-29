#include<bits/stdc++.h>

using namespace std;
void solve(){
	int n, q; cin >> n >> q;
	vector<int> v(n); for(auto &x : v)cin >> x;
	if(q >= n){
		cout << string(n,'1')+'\n';
		return;
	}
	int cn = 0;
	int ans = 0;
	string s(n,'0');
	for(int i = n-1; ~i; --i){
		if(v[i] > cn){
			if(cn < q){
				cn++;
				s[i] = '1';
			}
		}
		else s[i] = '1';
	}
	cout << s << '\n';

}

int main(){
	int t; cin >> t;
	while(t--)solve();

}