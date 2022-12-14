#include <bits/stdc++.h>
using namespace std;
#define N 100005

int n, a[N], ans;
bool tag;

int main(){
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", a + i);
		if(a[i] == i) ans++;
		else if(!tag && a[i] < i) tag = (a[a[i]] == i);
	}
	if(ans < n) ans += tag + 1;
	printf("%d", ans);
}