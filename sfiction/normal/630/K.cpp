#include <cstdio>

typedef long long ll;

ll n, ans;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

void DFS(int i, int s, bool flag){
	if (i > 10){
		if (flag)
			ans += n / s;
		else
			ans -= n / s;
		return;
	}
	DFS(i + 1, s, flag);
	DFS(i + 1, s * i / gcd(s, i), !flag);
}

int main(){
	scanf("%I64d", &n);
	DFS(2, 1, true);
	printf("%I64d\n", ans);
	return 0;
}