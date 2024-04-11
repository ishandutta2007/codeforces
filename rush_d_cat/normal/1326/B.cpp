#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
int n, b[N], a[N];
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	a[1]=b[1];
	int mx=a[1];
	for(int i=2;i<=n;i++){
		//b[i]=a[i]-mx
		a[i]=b[i]+mx;
		mx=max(mx,a[i]);
	}
	for(int i=1;i<=n;i++)printf("%d ", a[i]);
}