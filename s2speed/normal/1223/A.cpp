#include<iostream>

using namespace std;

int main(){
	int n , inp;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>inp;
		if(inp == 2){
			cout<<"2"<<endl;
		}
		else{
			cout<<inp % 2<<endl;
		}
	}
	return 0;
}