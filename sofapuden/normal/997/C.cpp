#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 998244353;
const int mxN = 1e6+5;

ll F[mxN];

ll pw(ll a, ll b){
	a%=M;
	ll r = 1;
	while(b){
		if(b&1)r = r * a % M;
		a = a * a % M;
		b >>= 1;
	}
	return r;
}

ll f(int n){
	return F[n];
}

ll C(int n, int k){
	return f(n) * pw(f(k) * f(n-k), M-2) % M;
}

int main(){
	ll n; cin >> n;
	memset(F,0,sizeof F);
	F[0] = 1;
	for(int i = 1; i < mxN; ++i)F[i] = F[i-1] * i % M;
	ll ans = pw(3,n*n)-pw(pw(3,n)-3,n);
	for(int i = 1; i <= n; ++i){
		ans -= C(n,i)*pw(-1,i)%M*(3*pw(pw(3,n-i)-1,n)+(pw(3,i)-3)*pw(3,(n-i)*n)%M);
		ans%=M;
	}
	cout << (ans % M + M) % M << '\n';
}