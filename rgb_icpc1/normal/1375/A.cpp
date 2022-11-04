#include<bits/stdc++.h>

using namespace std;
int a[10000];
int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int n, t;
	for(cin >> t; t --;) {
		cin >> n;
		for(int i = 0; i < n; i ++)  cin >> a[i];
		for(int i = 0; i < n ; i += 2) a[i] = abs(a[i]);
		for(int i = 1; i < n ; i += 2) a[i] = -abs(a[i]);
		for(int i = 0;i < n; i ++) cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}