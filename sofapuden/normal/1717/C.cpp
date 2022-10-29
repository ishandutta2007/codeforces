#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> A(n), B(n);
	for(auto &x : A)cin >> x;
	for(auto &x : B)cin >> x;
	for(int i = 0; i < n; ++i){
		if(A[i] > B[i]){
			cout << "NO\n";
			return;
		}
		if(A[i] == B[i])continue;
		if(B[i] > B[(i+1)%n]+1){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();

}