#include<iostream>
#include<string>

using namespace std;

int main(){
	int a , b , c;
	short t;
	cin>>t;
	while(t > 0){
		cin>>a>>b>>c;
		if(c > max(a , b)){
			if(a + b + 1 < c){
				cout<<"No"<<endl;
			}
			else{
				cout<<"Yes"<<endl;
			}
		}
		else{
			if(c + min(a , b) + 1 < max(a , b)){
				cout<<"No"<<endl;
			}
			else{
				cout<<"Yes"<<endl;
			}
		}
		t--;
	}
	return 0;
}