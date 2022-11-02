#include<bits/stdc++.h>
using namespace std;

#define N 200020

int a[N], n, mx, tot;
long long sum;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){
		scanf("%d", a + i);
		sum += a[i];
		mx = max(a[i], mx);
	}
	tot = (sum + n - 2) / (n - 1);
	mx = max(tot, mx);
	cout << mx << endl;
}