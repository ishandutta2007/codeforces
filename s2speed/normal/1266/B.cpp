#include<iostream>

using namespace std;

int main(){
	int t;
	long long x;
	cin>>t;
	while(t > 0){
		cin>>x;
		if(x < 15){
			cout<<"NO"<<endl;
		}
		else if(x % 14 >= 1 && x % 14 <= 6){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		t--;
	}
	return 0;
}