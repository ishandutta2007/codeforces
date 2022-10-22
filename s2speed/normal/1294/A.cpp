#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>

typedef long long int ll;
typedef double db;
typedef float fl;

using namespace std;

int main(){
	ll a , b , c , n , t , sum;
	cin>>t;
	while(t > 0){
		sum = 0;
		cin>>a>>b>>c>>n;
		sum = a + b + c + n;
		if(sum % 3 == 0 && sum / 3 >= max(max(a , b) , c)){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
		t--;
	}
	return 0;
}