#include<iostream>

using namespace std;

int main(){
	double a = 0 , n;
	cin>>n;
	for(double i = 1 ; i <= n ; i++){
		a += 1 / i;
	}
	cout<<a<<endl;
	return 0;
}