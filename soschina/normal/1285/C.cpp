#include <cstdio>
#include <iostream>
using namespace std;
const int N = 20;

int len;
long long x, tmp, a[N], ans = 1e12;

void dfs(int i, long long s){
	if(i <= len){
		dfs(i + 1, s * a[i]);
		dfs(i + 1, s);
	}else ans = min(ans, max(s, x / s));
}

int main(){
	scanf("%lld", &x);
	tmp = x;
	for(long long i = 2; i * i <= tmp; i++) if(tmp % i == 0){
		a[++len] = 1;
		do{
			a[len] *= i;
			tmp /= i;
		}while(tmp % i == 0);
	}
	if(tmp > 1) a[++len] = tmp;
	dfs(1, 1);
	printf("%lld %lld", x / ans, ans);
	return 0;
}