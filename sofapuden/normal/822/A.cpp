#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x). rend()

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
	int x, y; cin >> x >> y;
	int lo = min(x,y);
	int ans = 1;
	for(int i = 2; i <= lo; ++i){
		ans*=i;
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
}