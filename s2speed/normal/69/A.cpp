#include<iostream>

using namespace std;

int main(){
	int l , a , b , c , aa = 0 , bb = 0 , cc = 0;
	cin>>l;
	for(int i = 0 ; i < l ; i++){
		cin>>a>>b>>c;
		aa += a;
		bb += b;
		cc += c;
	}
	if(aa == 0 && bb == 0 && cc == 0){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}