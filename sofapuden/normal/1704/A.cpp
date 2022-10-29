#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	int n, m; cin >> n >> m;
	string a, b; cin >> a >> b;
	for(int i = 1; i < m; ++i){
		if(b[m-i] != a[n-i]){
			cout << "NO\n";
			return;
		}
	}
	for(int i = 0; i < n-m+1; ++i){
		if(a[i] == b[0]){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
	return;


}

int main(){
	int t; cin >> t;
	while(t--)solve();

}