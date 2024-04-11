#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	int mxx = 0, mnx = 0, mny = 0, mxy = 0;
	for(int i = 0; i < n; ++i){
		int x, y; cin >> x >> y;
		mxx = max(mxx,x);
		mnx = min(mnx,x);
		mxy = max(mxy,y);
		mny = min(mny,y);
	}
	cout << 2*(mxx+mxy-mny-mnx) << '\n';


}
int main(){
	int t; cin >> t;
	while(t--)solve();
}