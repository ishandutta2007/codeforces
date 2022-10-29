#include <bits/stdc++.h>
#define all(x) (x).begin, (x).end
#define rall(x) (x).rbegin, (x). rend

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
	int n, k; cin >> n >> k;
	int ans = 0;
	for(int i = 0, tmp; i < n; ++i){
		cin >> tmp;
		if(tmp + k <= 5){
			ans++;
		}
	}
	cout << ans/3 << "\n";
		
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
}