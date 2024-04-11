#include<iostream>

using namespace std;

int main(){
	int l , a[100];
	cin>>l;
	for(int i = 0 ; i < l ; i++){
		cin>>a[i];
		for(int j = i-1 ; j >= 0 ; j--){
			if(a[j] > a[j+1]){
				swap(a[j] , a[j + 1]);
			}
			else{
				break;
			}
		}
	}
	for(int i = 0 ; i < l ; i++){
		cout<<a[i]<<" ";
	}
	return 0;
}