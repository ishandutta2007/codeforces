#include<bits/stdc++.h>
#define s second
#define f first

using namespace std;

typedef long long ll;

void solve(){
	ll n, a, b; cin >> n >> a >> b;
	ll su = 1;
	while(su <= n){
		if((n-su)%b == 0){
			cout << "Yes\n";
			return;
		}
		su*=a;	
		if(a == 1)break;
	}
	cout << "No\n";
}

int main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
}