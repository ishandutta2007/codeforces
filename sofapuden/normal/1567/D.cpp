#include<bits/stdc++.h>

using namespace std;

const int MX = 3e5+5;

typedef long long ll;

int main(){
	int t; cin >> t;
	while(t--){
		ll s, n; cin >> s >> n;
		ll hi = 10;
		while(hi < s)hi*=10;
		hi/=10;
		for(int i = 0; i < n-1; ++i){
			while(s-hi < n-i-1){
				hi/=10;
			}
			cout << hi << ' ';
			s-=hi;
		}
		cout << s << '\n';
	}

}