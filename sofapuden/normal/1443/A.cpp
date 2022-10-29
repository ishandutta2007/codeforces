#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		for(int j = 4*n, i = 0; i < n; ++i, j-=2){
			cout << j << " \n"[i == n-1];
		}		
	}
}