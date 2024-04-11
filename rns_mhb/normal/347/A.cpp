#include <bits/stdc++.h>
using namespace std;

int n, a[105];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)	scanf("%d", &a[i]);
	sort(a, a + n);
	swap(a[0], a[n - 1]);
	for(int i = 0; i < n; i ++)	printf("%d%s", a[i], i < n - 1 ? " " : "");
}