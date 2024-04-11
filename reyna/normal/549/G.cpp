//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e6 + 9;
int arr[Maxn];
int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i = 0; i < n;i++) cin >> arr[i],arr[i] += i + 1;
	sort(arr,arr+n);
	for(int i = 1 ; i < n;i++){
		if(arr[i] == arr[i-1]){
			cout << ":(\n";
			return 0;
		}
	}
	for(int i = 0; i < n;i++){
		cout << arr[i] - i - 1 << ' ';
	}
	return 0;
}