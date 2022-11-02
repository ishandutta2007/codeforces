#include<bits/stdc++.h>
using namespace std;

#define N 100010

int a[N], d, mx, n;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	int d = 0, mx = 0;
	for(int i = 1; i <= n; i ++){
		d = __gcd(d, a[i]);
		mx = max(a[i], mx);
	}
//	cout << mx << endl;
	mx /= d;
	mx -= n;
	if(mx & 1) puts("Alice");
	else puts("Bob");
}