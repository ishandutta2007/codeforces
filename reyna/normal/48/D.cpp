//In the name of God
#include <iostream>
#include <cstdio>
using namespace std;
const int Maxn = 1e5 + 1e3;
int arr[Maxn];
int num[Maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n;i++){
		scanf("%d",&arr[i]);
		num[--arr[i]]++;
	}
	for(int i = 1; i < Maxn;i++){
		if(num[i] > num[i-1]){
			cout << -1 << endl;
			return 0;
		}
	}
	cout << num[0] << endl;
	for(int i = 0; i < n;i++){
		cout << num[arr[i]] << ' ';
		num[arr[i]]--;
	}
	cout << endl;
	return 0;
}