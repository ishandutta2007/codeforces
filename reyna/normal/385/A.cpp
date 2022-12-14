#include<iostream>
using namespace std;
int arr[1000];
int main(){
	int n,k;
	int max = -1;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < n-1; i++){
		if(max < arr[i]-arr[i+1]){
			max = arr[i]-arr[i+1];
		}
	}
	if(max-k > 0){
		cout << max-k;
	}else{
		cout << 0;
	}
}