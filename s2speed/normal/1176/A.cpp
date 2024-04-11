#include<iostream>

using namespace std;

int main(){
	long long n;
	int t;
	cin>>t;
	while(t > 0){
		cin>>n;
		for(int i = 0 ; i < 1000 ; i++){
			if(n == 1){
				cout<<i<<endl;
				break;
			}
			if(n % 2 == 0){
				n /= 2;
			}
			else if(n % 3 == 0){
					n = n / 3 * 2;
			}
			else if(n % 5 == 0){
				n = n / 5 * 4;
			}
			else{
				cout<<"-1"<<endl;
				break;
			}
		}
		t--;
	}
	return 0;
}