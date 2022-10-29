#include<bits/stdc++.h>

using namespace std;

const int MX = 3e5+5;

int main(){
	int t; cin >> t;
	vector<int> a(MX,0);
	for(int i = 1; i < MX; ++i){
		a[i] = a[i-1]^i;
	}
	while(t--){
		int a2, b; cin >> a2 >> b;
		int su = a[a2-1];
		if(su == b){
			cout << a2 << '\n';
			continue;
		}
		if((su^a2) == b){
			cout << a2+2 << '\n';
		}
		else{
			cout << a2+1 << '\n';
		}
	}

}