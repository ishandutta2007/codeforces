#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int t, n, i, x, y;
	
	cin >> t;
	
	while(t --){
		cin >> n >> x >> y;
		
		int d = y - x, diff;
		int first, res = 1e9, res_diff;
		
		for(diff = 1; diff <= d; diff ++) if(d % diff == 0){
			
			if(y - diff * (n - 1) > x) continue;
			
			int cnt = min(n - 1, y / diff);
			first = y - cnt * diff;
			if(first == 0) first += diff;
			if(res > (first + (n - 1) * diff)){
				res = (first + (n - 1) * diff);
				res_diff = diff;
			}
		}
		
		for(i = 0; i < n; i ++){
			if(i) cout << " ";
			cout << res;
			res -= res_diff;
		}
		cout << endl; 
	}
	
	return 0;
}