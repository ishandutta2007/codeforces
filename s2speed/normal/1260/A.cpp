#include<iostream>

using namespace std;

int main(){
	long long n , c , sum , counter;
	cin>>n;
	for(int f = 0 ; f < n ; f++){
		cin>>c>>sum;
		counter = 0;
		counter += (sum / c) * (sum / c) * c;
		counter += ((sum % c) * (sum / c * 2 + 1));
		cout<<counter<<endl;
	}
	return 0;
}