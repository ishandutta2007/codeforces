#include<iostream>

using namespace std;

int main(){
	int n , input , a[101];
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		cin>>input;
		a[input] = i;
	}
	for(int i = 1 ; i <= n ; i++){
		cout<<a[i]<<" ";
	}
	return 0;
}