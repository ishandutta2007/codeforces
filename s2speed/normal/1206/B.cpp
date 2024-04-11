#include<iostream>

typedef long long ll;

using namespace std;

int main(){
	ll n , c = 0 , ans = 0 , z = 0 , h;
	cin>>n;
	while(n > 0){
		cin>>h;
		if(h == 0){
			z++;
		} else if(h > 0){
			ans += h - 1;
		} else {
			ans -= h + 1;
			c++;
		}
		n--;
	}
	if(z > 0){
		cout<<ans + z<<endl;
	} else if(c % 2 == 1){
		cout<<ans + 2<<endl;
	} else {
		cout<<ans<<endl;
	}
	return 0;
}