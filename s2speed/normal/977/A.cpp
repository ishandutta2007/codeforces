#include<iostream>

using namespace std;

int main(){
	int a , l;
	cin>>a>>l;
	for(int i = 0 ; i < l ; i++){
		if(a % 10 == 0){
			a /= 10;
		}
		else{
			a--;
		}
	}
	cout<<a<<endl;
	return 0;
}