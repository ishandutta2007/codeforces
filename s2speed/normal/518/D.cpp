#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

double tav(double n , ll k){
	if(k == 0){
		return 1;
	}
	double x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n , t;
	double p , ans;
	cin>>n>>p>>t;
	if(p == 1){
		cout<<min(n , t)<<"\n";
		return 0;
	}
	if(p == 0){
		cout<<"0 \n";
		return 0;
	}
	if(n >= t){
		ans = p * t;
	} else {
		double q , h;
		q = 1 - p;
		h = tav(q , t);
		ans = n;
		for(int i = 0 ; i < n ; i++){
			if(i != 0){
				h *= (t - i + 1);
				h /= i;
			}
			ans -= h * (n - i);
			h /= q;
			h *= p;
		}
	}
	printf("%.8lf\n" , ans);
	return 0;
}