#include<iostream>

using namespace std;

int main(){
	int n , a[128] , maxi = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		for(int j = i ; j > 0 ; j--){
			if(a[j] > a[j - 1]){
				swap(a[j] , a[j - 1]);
			}
			else{
				break;
			}
		}
	}
	cout<<a[0]<<" ";
	for(int i = 1 ; i < n ; i++){
		if(a[0] % a[i] != 0){
			cout<<a[i]<<endl;
			break;
		}
		else if(a[i] == a[i - 1]){
			cout<<a[i]<<endl;
			break;
		}
	}
	return 0;
}