#include <cstdio>
#include <cstring>

int main(){
	int s[10] = {1989};
	for (int t = 1, i = 1; i < 10; ++i)
		s[i] = s[i - 1] + (t *= 10);

	int n;
	char A[20];
	scanf("%d", &n);
	for (int t, i = 0; i < n; ++i){
		scanf("\nIAO'%s", A);
		int l = strlen(A) - 1, e = 1;
		for (int j = l; j >= 0; --j)
			e *= 10;
		sscanf(A, "%d", &t);

		printf("%d\n", s[l + (t < s[l] % e)] / e * e + t);
	}
	return 0;
}