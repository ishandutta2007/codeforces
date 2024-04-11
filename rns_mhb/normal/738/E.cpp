#include <bits/stdc++.h>
using namespace std;
#define N 200005

int n, a[N], s, ans, b;

int main(){
	int i, j = 1;
	scanf("%d %d", &n, &s);
	for(i = 1; i <= n; i++){
		scanf("%d", &b);
		if(i == s) ans += (b != 0);
		else a[j++] = b;
	}
	sort(a + 1, a + n);
	i = 1; j = 0;
	while(a[i] == 0 && i < n) ans++, i++, j++;
	for( ; i < n; i++){
		if(a[i] - a[i - 1] <= 1) continue;
		else{
			if(j) j--;
			else ans++, n--;
			a[i - 1]++; i--;
		}
	}
	cout << ans;
}