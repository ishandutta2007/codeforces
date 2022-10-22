#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll t , s , sum  , h;
	cin>>t;
	while(t > 0){
		sum = 0;
		cin>>s;
		while(s >= 10){
			sum += (s / 10) * 10;
			h = s;
			s /= 10;
			s += h % 10;
		}
		sum += s;
		cout<<sum<<endl;
		t--;
	}
	return 0;
}