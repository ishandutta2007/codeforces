#include<iostream>

using namespace std;

int main(){
	long long n;
	cin>>n;
	if(n == 1){
		cout<<"9 8"<<endl;
	}
	else{
		cout<<3*n<<" "<<2*n<<endl;
	}
	return 0;
}