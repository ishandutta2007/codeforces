#include<iostream>

using namespace std;

int main(){
	long long t , a , b , n , s;
	cin>>t;
	while(t > 0){
		cin>>a>>b>>n>>s;
		if(s > a * n + b){
			cout<<"NO"<<endl;
		}
		else if(s % n > b){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
		t--;
	}
	return 0;
}