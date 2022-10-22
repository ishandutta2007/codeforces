#include<iostream>

typedef long long ll;

using namespace std;

int main(){
	ll n , h[2] , a = 1 , m = 0;
	cin>>n;
	cin>>h[0];
	for(int i = 1 ; i < n ; i++){
		cin>>h[1];
		if(h[1] > h[0]){
			a++;
		} else {
			m = max(m , a);
			a = 1;
		}
		h[0] = h[1];
	}
	cout<<max(a , m)<<endl;
	return 0;
}