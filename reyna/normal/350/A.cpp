#include <iostream>
using namespace std;
int main(){
	int n;
	int m;
	cin >> n >> m;
	int min=1000000000,max=0,min2=1000000000;
	for(int i = 0; i < n;i++){
		int a;
		cin>>a;
		if(a < min2){
			min2 = a;
		}
		if(a > max){
			max = a;
		}
	}
	for(int i = 0; i < m;i++){
		int a;
		cin >>a;
		if(a < min){
			min = a;
		}
	}
	if(min > max && max/2 >= min2){
		cout << max;
	}else if(min > 2*min2 && 2*min2 >= max){
		cout << 2*min2;
	}else{
		cout << -1;
	}
	
}