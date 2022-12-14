//In the name of God
#include <bits/stdc++.h>
using namespace std;
int ans[2][2];
int arr[1000000];
int main(){
	ios_base::sync_with_stdio(0);
	ans[0][0] = 1;
	ans[1][0] = 0;
	ans[0][1] = 1;
	ans[1][1] = 1;
	int n;
	cin >> n;
	for(int i = 0; i < n;i++) cin >> arr[i];
	if(n == 1 && arr[0] == 0){
		cout << "YES\n";
		cout << "(0)\n";
		return 0;
	}
	if(arr[n-1] == 1){
		cout << "NO\n";
		return 0;
	}
	int cur = 0;
	for(int i = n - 2; i + 1; --i){
		if(i == n - 2){
			cur = arr[n-2];
			continue;
		}
		cur = ans[arr[i]][cur];
	}
	if(cur == 1){
		cout << "YES\n";
		cout << '(';
		for(int i = 0; i < n - 1;i++){
			if(i) cout << "->";
			cout << '(';
			cout << arr[i];
		}
		for(int i = 0; i < n - 1; i ++) cout << ')';
		cout << "->";
		cout << 0 << ')';
	}else{
		cout << "NO\n";
	}
}