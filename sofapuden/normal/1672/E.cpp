#include<bits/stdc++.h>

using namespace std;

int que(int x){
	cout << "? " << x << endl;
	int ret; cin >> ret;
	return ret;
}

void solve(int testID){
	int n; cin >> n;
	int l = 1, r = 5e6, bes = 5e6;
	while(l <= r){
		int m = (l+r)>>1;
		int q = que(m);
		if(q == 1)r = m-1, bes = m;
		else l = m+1;
	}
	int ans = bes;
	for(int i = 2; i <= n; ++i){
		int cu = bes-i+1;
		int sz = (cu+i-1)/i;
		int q = que(sz);
		if(!q)break;
		ans = min(ans,q*sz);
	}
	cout << "! " << ans << endl;
}

int main(){
	solve(0);
	return 0;
	int t; cin >> t;
	int cn = 1;
	while(t--){
		solve(cn++);

	}

}