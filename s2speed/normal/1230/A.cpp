#include<iostream>

using namespace std;

int main(){
	int a , b , c , d;
	cin>>a>>b>>c>>d;
	if(max(max(a,b),max(c,d)) + min(min(a,b),min(c,d)) == max(min(a,b),min(c,d)) + min(max(a,b),max(c,d)) || min(min(a,b),min(c,d)) + max(min(a,b),min(c,d)) + min(max(a,b),max(c,d)) == max(max(a,b),max(c,d))){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}