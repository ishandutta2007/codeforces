#include <cstdio>

const int MAXN = 1E3 + 10, MAXA = 2E6 + 10;

int n, a[MAXN];
int np, prime[MAXA];
bool isnp[MAXA + 1];

void getPrime(){
	np = 0;
	isnp[0] = isnp[1] = true;
	for (int i = 2; i <= MAXA; ++i){
		if (!isnp[i])
			prime[np++] = i;
		for (int j = 0; j < np && prime[j] <= MAXA / i; ++j){
			isnp[prime[j] * i] = true;
			if (i % prime[j] == 0)
				break;
		}
	}
}

int main(){
	getPrime();

	scanf("%d" ,&n);
	int cnt = 0;
	int A = 0, B = 0, C = 0;
	for (int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		if (a[i] == 1)
			++cnt;
		else{
			if (!A && !isnp[a[i] + 1])
				A = a[i];
		}
		for (int j = 0; !B && j < i; ++j)
			if (!isnp[a[i] + a[j]])
				B = a[j], C = a[i];
	}
	if (!!A + cnt >= 3){
		printf("%d\n", cnt + !!A);
		if (A)
			printf("%d ", A);
		for (int i = 0; i < cnt; ++i)
			printf("1%c", "\n "[i < cnt - 1]);
	}
	else if (B){
		printf("2\n%d %d\n", B, C);
	}
	else
		printf("1\n%d\n", a[0]);
	return 0;
}