#include<iostream>

using namespace std;

int main(){
	int  m , n;
	cin>>m>>n;
	if(m % 2 == 0 && n % 2 == 0){
		cout<<m/2*n<<endl;
	}
	else if(m % 2 == 0 && n % 2 != 0){
		cout<<m/2*n<<endl;
	}
	else if(m % 2 != 0 && n % 2 == 0){
		cout<<n/2*m<<endl;
	}
	else{
		cout<<(n*m-1)/2<<endl;
	}
	return 0;
}