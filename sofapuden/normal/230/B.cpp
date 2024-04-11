#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

set<ll> s;

void precom(){
	for(ll i = 2; i < sqrt(1e12+5); i++){
		bool ok = 1;
		for(int j = 2; j <= sqrt(i); ++j){
			if(i%j == 0){
				ok = 0;
				break;
			}
		}
		if(ok){
			s.insert(i*i);
		}
	}
}

int main(){
	precom();
	int n; cin >> n;
	for(int i = 0; i < n; ++i){
		ll tmp;
		cin >> tmp;
		if(s.count(tmp)){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}		
	
}