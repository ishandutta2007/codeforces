#include <bits/stdc++.h>

using namespace std;
typedef long long INT;

void calc(INT x,INT y){
	if(x<=1&&y<=1) return;
	if(x>y){
		printf("%I64dA",(x-1)/y);
		calc(x%y,y);
	}
	else{
		printf("%I64dB",(y-1)/x);
		calc(x,y%x);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	INT a,b;
	scanf("%I64d%I64d",&a,&b);
	if(__gcd(a,b)>1) puts("Impossible");
	else calc(a,b);
    return 0;
}