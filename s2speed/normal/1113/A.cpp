#include<iostream>

typedef long long ll;

using namespace std;

int main(){
	ll counter = 0 , n , v;
	cin>>n>>v;
	if(v >= n - 1){
		cout<<n - 1<<endl;
		return 0;
	}
	counter += v;
	for(int i = 2 ; i + v <= n ; i++){
		counter += i;
	}
	cout<<counter<<endl;
	return 0;
}