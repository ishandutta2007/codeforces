#include <iostream>
using namespace std;
int arr[100000];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n-1;i++){
		cin >> arr[i];
	}
	int a,b;
	cin >> a >> b;
	int counter = 0;
	for(int i = a-1; i < b-1;i++){
		counter += arr[i];
	}
	cout << counter;
	
}