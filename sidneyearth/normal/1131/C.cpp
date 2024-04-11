#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 110;
int a[maxn], b[maxn];
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	int p = 2, q = n; b[1] = a[1];
	for(int j = 2; j <= n; j++){
		if(j & 1) b[p++] = a[j];
		else b[q--] = a[j];
	}
	for(int j = 1; j <= n; j++)
		printf("%d%c", b[j], " \n"[j == n]);
	return 0;
}