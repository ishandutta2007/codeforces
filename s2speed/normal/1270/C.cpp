#include<iostream>

using namespace std;

int main(){
	int t , n , a;
	long long z , x;
	cin>>t;
	while(t > 0){
		cin>>n;
		z = 0;
		x = 0;
		for(int i = 0 ; i < n ; i++){
			cin>>a;
			z += a;
			x = x ^ a;
		}
		cout<<2<<endl;
		cout<<x<<" "<<z + x<<endl;;
		t--;
	}
	return 0;
}