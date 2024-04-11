#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll n;

ll bdraw(ll v[] , ll u[]){
	ll h , a[3] , b[3] , ans = 0;
	for(int i = 0 ; i < 3 ; i++){
		a[i] = v[i];
		b[i] = u[i];
	}
	h = min(a[0] , b[2]); a[0] -= h; b[2] -= h;
	h = min(a[1] , b[0]); a[1] -= h; b[0] -= h;
	h = min(a[2] , b[1]); a[2] -= h; b[1] -= h;
	a[0] -= min(a[0] , b[0]); ans += a[0];
	a[1] -= min(a[1] , b[1]); ans += a[1];
	a[2] -= min(a[2] , b[2]); ans += a[2];
	return ans;
}

ll drawb(ll v[] , ll u[]){
	ll h , a[3] , b[3] , ans = n;
	for(int i = 0 ; i < 3 ; i++){
		a[i] = v[i];
		b[i] = u[i];
	}
	h = min(a[0] , b[0]); a[0] -= h; ans -= h;
	h = min(a[1] , b[1]); a[1] -= h; ans -= h;
	h = min(a[2] , b[2]); a[2] -= h; ans -= h;
	h = min(a[0] , b[2]); ans -= h;
	h = min(a[1] , b[0]); ans -= h;
	h = min(a[2] , b[1]); ans -= h;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll a[3] , b[3] , ans[2] , h; ans[0] = 0; ans[1] = 0;
	cin>>n>>a[0]>>a[1]>>a[2]>>b[0]>>b[1]>>b[2];
	ans[1] += min(a[0] , b[1]) + min(a[1] , b[2]) + min(a[2] , b[0]);
	ans[0] = bdraw(a , b);
	ans[0] = min(ans[0] , drawb(a , b));
//	cout<<drawb(a , b)<<" "<<bdraw(a , b)<<"\n";
	cout<<ans[0]<<" "<<ans[1]<<"\n";
	return 0;
}