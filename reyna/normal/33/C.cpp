#include <iostream>
using namespace std;
int arr[100000];
int main(){
	int n;
	cin >> n;
	int counter = 0;
	int b;
	cin >> b;
	counter = b;
	arr[0] = max(b,0);
	for(int i = 1; i < n;i++){
		int a;
		cin >> a;
		counter += a;
		arr[i] = max(arr[i-1]+a,0);
	}
	int answer = 0;
	for(int i = 0; i < n;i++){
		answer = max(answer,arr[i]);
	}
	cout << (counter-answer)*(-1) + answer << endl;
	return 0;
}