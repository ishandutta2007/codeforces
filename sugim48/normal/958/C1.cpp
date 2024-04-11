#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(int)(N);i++)
#define show(x) cout<< #x<< " "<<(x)<<endl;
#define chmax(x,y) x = max(x,y)
using namespace std;
using ll = long long;
int N,p;
int main(){
	cin>>N>>p;
	vector<ll> a(N);
	ll S = 0;
	rep(i,N){
		cin>>a[i];
		S += a[i];
	}
	ll L = 0;
	ll ans =0 ;
	rep(i,N-1){
		L += a[i];
		ll R = S-L;
		chmax(ans,L%p+R%p);
	}
	cout<<ans<<endl;
}