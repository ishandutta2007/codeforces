#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
	int a;
	cin>>a;
	for(int i=1;i<a;i++){
		for(int j=1;j<a;j++){
			int d=i*j;
			if(d>=a)
				cout<<d/a;
			cout<<d%a;
			cout <<' ';
		}
		cout<<'\n';
	}
	return 0;
}