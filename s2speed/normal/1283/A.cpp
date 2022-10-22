#include<iostream>

using namespace std;

int main(){
	int t , h , m;
	cin>>t;
	while(t > 0){
		cin>>h>>m;
		if(m == 0){
			cout<<(24 - h) * 60<<endl;
		}
		else{
			cout<<(23 - h) * 60 + 60 - m<<endl;
		}
		t--;
	}
	return 0;
}