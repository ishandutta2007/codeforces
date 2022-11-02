#include <bits/stdc++.h>
using namespace std;

int n, a[100005], ans;
bool flag;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)	scanf("%d", &a[i]);
	for(int i = 0; i < n; i ++){
		if(a[i] == i)	ans ++;
		else if(a[a[i]] == i)	flag = 1;
	}
	if(ans == n)	printf("%d", ans);
	else if(flag == 0)	printf("%d", ans + 1);
	else	printf("%d", ans + 2);
}