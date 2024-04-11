#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e9+7;

void solve(){
	int n; cin >> n;
	int od = 0, ev = 0;
	for(int i = 0; i < n; ++i){
		int x; cin >> x;
		if(x&1)od++;
		else ev++;
	}
	if(!od){
		cout << "Alice\n";
		return;
	}
	if(!ev){
		if(((od+1)/2)&1){
			cout << "Bob\n";
			return;
		}
		else{
			cout << "Alice\n";
			return;
		}
	}
	if((od&1) && (ev&1)){
		cout << "Alice\n";
		return;
	}
	if(!(od & 1) && !(ev & 1)){
		if((od/2)&1){
			cout << "Bob\n";
			return;
		}
		else{
			cout << "Alice\n";
			return;
		}
	}
	if(od&1){
		if(((od+1)/2) & 1){
			cout << "Bob\n";
			return;
		}
		else{
			cout << "Alice\n";
			return;
		}
	}
	if(ev&1){
		if((od/2) & 1){
			cout << "Bob\n";
			return;
		}
		else{
			cout << "Alice\n";
			return;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();
}