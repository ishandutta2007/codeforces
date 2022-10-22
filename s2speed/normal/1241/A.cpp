#include<iostream>

using namespace std;

int main(){
	int n , inp;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>inp;
		if(inp < 4){
			cout<<4 - inp<<endl;
		}
		else{
			if(inp % 2 == 0){
				cout<<"0"<<endl;
			}
			else{
				cout<<"1"<<endl;
			}
		}
	}
	return 0;
}