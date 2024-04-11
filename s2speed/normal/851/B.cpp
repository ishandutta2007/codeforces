#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 0;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

double gh(double a , double b){
	double h = a - b;
	if(h < 0){
		h = 0 - h;
	}
	return h;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	double ax , ay , bx , by , cx , cy , lab , lbc , shibab , shibbc;
	cin>>ax>>ay>>bx>>by>>cx>>cy;
	lab = gh(ax , bx) * gh(ax , bx) + gh(ay , by) * gh(ay , by);
	lbc = gh(bx , cx) * gh(cx , bx) + gh(cy , by) * gh(cy , by);
	shibab = (ax - bx) / (ay - by);
	shibbc = (bx - cx) / (by - cy);
	if(lab == lbc && shibab != shibbc){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
	return 0;
}