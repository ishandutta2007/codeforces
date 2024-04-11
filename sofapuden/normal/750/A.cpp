#include <bits/stdc++.h>
#define all(x) (x).begin, (x).end
#define rall(x) (x).rbegin, (x). rend

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
	int n, k; cin >> n >> k;
	k = 240-k;
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		k-=i*5;
		if(k < 0){
			cout << ans << "\n";
			return;
		}
		++ans;
	}
	cout << ans << "\n";
	return;
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
}