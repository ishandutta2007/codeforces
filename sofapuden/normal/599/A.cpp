#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
	vi v(3);
	for(int i = 0; i < 3; ++i){
		cin >> v[i];
	}
	sort(all(v));
	int ans = v[0]+v[1];
	ans += min(ans,v[2]);
	cout << ans << "\n";
			
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
}