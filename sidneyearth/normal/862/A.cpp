#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, x;
	scanf("%d%d", &n, &x);
	int ans = x;
	for(int i = 0; i < n; i++){
		int t; scanf("%d", &t);
		if(t < x) ans--;
		else if(t == x) ans++;
	}
	printf("%d\n", ans);
	return 0;
}