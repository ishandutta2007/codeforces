#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
	int n, k1, k2; cin >> n >> k1 >> k2;
	int b1 = 0, b2 = 0;
	for(int i = 0, tmp; i < k1; ++i){
		cin >> tmp;
		b1 = max(b1,tmp);
	}
	for(int i = 0, tmp; i < k2; ++i){
		cin >> tmp;
		b2 = max(b2,tmp);
	}
	cout << (b1 > b2 ? "YES\n" : "NO\n");
	return;
}

int main(){
	int t; cin >> t; while(t--){solve();}	
}