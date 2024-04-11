#include<iostream>

using namespace std;

int main(){
	int n , a , b;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a>>b;
		if(a >= b){
			cout<<"YES"<<endl;
		}
		else if(a > 3 && b > 3){
			cout<<"YES"<<endl;
		}
		else if(a == 1){
			cout<<"NO"<<endl;
		}
		else if(a < 4 && b < 4){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}