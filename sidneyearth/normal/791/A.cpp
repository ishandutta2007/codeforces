#include<bits/stdc++.h>
using namespace std;
int main(){
	int a, b, ans = 0;
	scanf("%d%d", &a, &b);
	while(a <= b){
		a *= 3;
		b *= 2;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}