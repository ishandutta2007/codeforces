#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool que(int l, int r){
	cout << "? " << l << ' ' << r << endl;
	int ans = 0;
	for(int i = l; i <= r; ++i){
		int x; cin >> x;
		ans += (x >= l && x <= r);
	}
	return ans&1;
}

void solve(){
	int n; cin >> n;
	int l = 1, r = n;
	while(l < r){
		int m = (l+r) >> 1;
		if(que(l,m)){
			r = m;
		}
		else{
			l = m+1;
		}
	}
	cout << "! " << l << endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();
}