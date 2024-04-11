#include<iostream>

using namespace std;

int main(){
	int l , a , b , counter = 0;
	cin>>l;
	for(int i = 0 ; i < l ; i++){
		cin>>a>>b;
		if(b-a > 1){
			counter++;
		}
	}
	cout<<counter<<endl;
	return 0;
}