//In the name of God
#include <iostream>
using namespace std;
bool mark[123];
int arr[123],b[123];
int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> arr[i] >> b[i];
	for(int i = 0; i < n;i++){
		for(int j = 0; j < n;j++){
			if(i != j){
				if(arr[j] == b[i])
					mark[j] = 1;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n;i++)
		ans += mark[i];
	cout << n - ans << endl;
	return 0;
}