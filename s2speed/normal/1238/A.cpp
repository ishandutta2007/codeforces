#include<iostream>

using namespace std;

int main(){
	int n;
	long long a , b;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a>>b;
		if(a - b == 1){
			cout<<"NO"<<endl;
		}
		else if(a - b > 1){
			cout<<"YES"<<endl;
		}
	}
	return 0;
}