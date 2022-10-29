#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	string a1, a2; cin >> a1 >> a2;
	for(int i = 0; i < n; ++i){
		if(a1[i] == 'G')a1[i] = 'B';
		if(a2[i] == 'G')a2[i] = 'B';
		if(a1[i] != a2[i]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main(){
	int t; cin >> t;
	while(t--)solve();

}