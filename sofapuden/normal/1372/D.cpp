#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n; cin >> n;
	vector<ll> v(n);
	for(auto &x : v) cin >> x;
	vector<ll> v2;
	for(int i = 0; i <= 1; ++i){
		for(int j = 0; j < n; j+=2){
			v2.push_back(v[j]);
		}
		for(int j = 1; j < n; j+=2){
			v2.push_back(v[j]);
		}
	}
	ll su = 0;
	for(int i = 0; i < (n+1)/2; ++i){
		su+=v2[i];
	}
	ll bes = su;
	int l = (n+1)/2, r = 0;
	while(l < 2*n){
		su+=v2[l++];
		su-=v2[r++];
		bes = max(bes,su);
	}
	cout << bes << '\n';
}