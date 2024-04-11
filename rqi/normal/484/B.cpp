#include <bits/stdc++.h>
using namespace std;

const int mx = 200005;
int n;
int a[mx];
bool pres[1000005];
int highunder[1000005];

int highestUnder(int x){
	if(x > 1000001) return highunder[1000001];
	return highunder[x];
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pres[a[i]] = 1;
	}
	for(int i = 1; i <= 1000001; i++){
		highunder[i] = highunder[i-1];
		if(pres[i-1]) highunder[i] = i-1;
	}
	int ans = 0;
	for(int i = 1; i <= 1000000; i++){
		if(!pres[i]) continue;
		for(int j = 2*i; j <= 2000000; j+=i){
			int x = highestUnder(j);
			if(x >= i) ans = max(ans, x % i);
		}
	}
	cout << ans << "\n";
}