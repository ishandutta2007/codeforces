#include<iostream>

typedef long long ll;

using namespace std;

ll a9(ll a){
	ll i = a + 1 , counter = -1;
	while(i > 0){
		counter++;
		i /= 10;
	}
	return counter;
}

int main(){
	ll t , a , b;
	cin>>t;
	while(t > 0){
		cin>>a>>b;
		cout<<a * a9(b)<<endl;
		t--;
	}
}