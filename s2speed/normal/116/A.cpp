#include<iostream>

using namespace std;

int main(){
	int l , a , b , p = 0 , m = 0;
	cin>>l;
	for(int i = 0 ; i < l ; i++){
		cin>>a>>b;
		p += (b - a);
		if(p > m){
			m = p;
		}
	}
	cout<<m<<endl;
	return 0;
}