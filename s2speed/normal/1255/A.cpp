#include<iostream>

using namespace std;

int main(){
	int t , a , b , e , counter;
	cin>>t;
	while(t > 0){
		cin>>a>>b;
		counter = 0;
		e = max(a,b) - min(a,b);
		counter += e / 5;
		e %= 5;
		counter+= e / 2;
		e %= 2;
		counter += e;
		cout<<counter<<endl;
		t--;
	}
	return 0;
}