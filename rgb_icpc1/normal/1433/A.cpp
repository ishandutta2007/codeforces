#include<bits/stdc++.h>

using namespace std;

int calc(int n){
	int cnt = 0, res = 0;
	while(n){
		cnt ++;
		n /= 10;
	}
	
	for(int i = 1; i <= cnt; i ++) res += i;
	return res;
}

int main(){
	
//	freopen("in.txt", "r", stdin);
	
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t, n, i;
	
	cin >> t;
	
	while(t --){
		cin >> n;
		int x = n % 10;
		int res = (x - 1) * 10;
		res += calc(n);
		
		cout << res << endl;
	}
	
	return 0;
}