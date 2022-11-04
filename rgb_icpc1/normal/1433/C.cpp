#include<bits/stdc++.h>

using namespace std;

#define M 300005

int a[M];

int main(){
	
//	freopen("in.txt", "r", stdin);
	
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t, n, i;
	
	cin >> t;
	
	while(t --){
		cin >> n;
		
		int mx = 0;
		
		for(i = 0; i < n; i ++) {
			cin >> a[i];
			mx = max(mx, a[i]);
		}
		
		for(i = 0; i < n; i ++) if(a[i] == mx){
			if(i && a[i] > a[i - 1]) break;
			if(i < n - 1 && a[i] > a[i + 1]) break;
		}
		
		if(i == n) cout << -1 << endl;
		else cout << i + 1 << endl;
	}
	
	return 0;
}