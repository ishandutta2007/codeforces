#include <bits/stdc++.h>
#define all(x) (x).begin, (x).end
#define rall(x) (x).rbegin, (x). rend

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
	int a, b, n; cin >> a >> b >> n;
	int ans = 1;
	while(n>0){
		
		n-= __gcd((ans%2 == 0 ? b : a),n);
		ans++;
	}
	cout << ans%2 << "\n";
			
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
}