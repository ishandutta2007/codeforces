#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; scanf("%d", &n);
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int grade = a + b + c + d;
	int ans = 1;
	for(int i = 2; i <= n; i++){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if(a + b + c + d > grade) ans++;
	}
	printf("%d\n", ans);
	return 0;
}