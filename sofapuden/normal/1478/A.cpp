#include<bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		map<int,int> M;
		int mx = 0;
		for(int i = 0; i < n; ++i){
			int a; cin >> a;
			M[a]++;
			mx = max(mx,M[a]);
		}
		cout << mx << "\n";
	}
}