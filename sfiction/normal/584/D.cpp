#include <cstdio>

bool isprime(int x){
	if (x == 1)
		return false;
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return false;
	return true;
}

int main(){
	int n;
	scanf("%d", &n);
	if (isprime(n))
		printf("1\n%d\n", n);
	else if (isprime(n - 2))
		printf("2\n%d %d\n", 2, n - 2);
	else{
		int i = 4;
		for (; i < n; i += 2)
			if (isprime(n - i))
				break;
		for (int j = 2; j < i; ++j)
			if (isprime(j) && isprime(i - j)){
				printf("3\n%d %d %d\n", j, i - j, n - i);
				break;
			}
	}
	return 0;
}