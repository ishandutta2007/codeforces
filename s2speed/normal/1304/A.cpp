#include<iostream>

typedef long long ll;

using namespace std;

int main(){
	ll t;
	cin>>t;
	while(t > 0){
		ll x , y , a , b , s , c;
		cin>>x>>y>>a>>b;
		s = y - x;
		c = a + b;
		if(s % c != 0){
			cout<<-1<<endl;
		} else {
			cout<<s / c<<endl;
		}
		t--;
	}
	return 0;
}