#include<bits/stdc++.h>
using namespace std;

#define N 100010

int a[N], n;

int main(){
	//freopen("a.in", "r", stdin);
	scanf("%d", &n);
	for( int i = 1; i <= n; i ++) scanf("%d", a + i);
	int tot = 0;
	for(int i = 1; i <= n; i ++){
			for(int j = i + 1; j <= n; j ++){
				if(a[i] > a[j]) tot ++;
			}
	}
	if(tot & 1) cout << 2 * tot - 1 << endl;
	else cout << 2 * tot << endl;
}