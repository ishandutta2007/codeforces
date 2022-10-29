#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x). rend()

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
	ll n, y; cin >> n >> y;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		char c;
		int tmp; cin >> c >> tmp;
		if(c == '+'){
			y+=tmp;
		}
		else{
			if(tmp <= y){
				y-=tmp;
			}
			else{
				ans++;
			}
		}
	} 
	cout << y << " " << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
}