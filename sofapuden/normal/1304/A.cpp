#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef vector<int> vi;


void solve(){
	int a, b, c, d; cin >> a >> b >> c >> d;
	if((b-a)%(c+d) == 0){
		cout << (b-a)/(c+d) << "\n";
	}
	else{
		cout << "-1\n";
	}
			
}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int t; cin >> t;
	while(t--){
	solve();
}
}