#include<iostream>

using namespace std;

int main(){
	long long n , k;
	cin>>n>>k;
	if(n % 2 != 0){
		if(k <= (n+1)/2){
			cout<<k*2 - 1<<endl;
		}
		else{
			cout<<(k - (n+1)/2) * 2<<endl;
		}
	}		
	else{
		if(k <= n/2){
			cout<<k*2 - 1<<endl;
		}
		else{
			cout<<(k-n/2)*2<<endl;
		}
	}
	return 0;
}