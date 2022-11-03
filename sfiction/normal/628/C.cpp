#include <cstdio>

const int MAXN = 1E5 + 10;

char a[MAXN], b[MAXN];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", a);
	int i = 0;
	for (; k && i < n; ++i){
		if (a[i] <= 'm'){
			if ('z' - a[i] <= k)
				b[i] = 'z', k -= 'z' - a[i];
			else
				b[i] = a[i] + k, k = 0;
		}
		else{
			if (a[i] - 'a' <= k)
				b[i] = 'a', k -= a[i] - 'a';
			else
				b[i] = a[i] - k, k = 0;
		}
	}
	for (; i < n; ++i)
		b[i] = a[i];
	b[n] = '\0';
	puts(k ? "-1" : b);
	return 0;
}