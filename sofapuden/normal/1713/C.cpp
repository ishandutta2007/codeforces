#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	n--;
	if(!n){
		cout << 0 << '\n';
		return;
	}
	int x = n;
	vector<int> v(n);
	vector<int> nxt(3*n,0);
	for(int i = 1; i*i < 3*n; ++i){
		for(int j = i*i; j > (i-1)*(i-1); --j){
			nxt[j] = i*i;
		}
	}
	vector<int> ans;
	while(~n){
		for(int i = nxt[n]-n; i <= n; ++i){
			ans.push_back(i);
		}
		n = x-ans.size();
	}
	reverse(ans.begin(),ans.end());
	for(auto x : ans)cout << x << ' ';
	cout << '\n';
}
int main(){
	int t; cin >> t;
	while(t--)solve();
}