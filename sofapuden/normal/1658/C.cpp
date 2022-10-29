#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x : v)cin >> x;
	if(n == 1){
		cout << "YES\n";
		return;
	}
	int x = -1;
	for(int i = 0; i < n; ++i){
		if(v[i] == 1){
			if(x != -1){
				cout << "NO\n";
				return;
			}
			x = i;
		}
	}
	if(x == -1){
		cout << "NO\n";
		return;
	}
	int pr = 1;
	for(int i = x; (++i)%n != x;){
		i%=n;
		if(v[i] > pr+1){
			cout << "NO\n";
			return;
		}
		pr = v[i];	
	}
	cout << "YES\n";
}

int main(){
	int t; cin >> t;
	while(t--)solve();
}