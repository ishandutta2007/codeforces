#include <stdio.h>
const int maxn = 1010;
int a[maxn], b[maxn];
int main(){
	int n, s;
	scanf("%d%d", &n, &s);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	bool ans;
	if(!a[1])
		ans = false;
	else if(a[s])
		ans = true;
	else if(!b[s])
		ans = false;
	else{
		ans = false;
		for(int i = s; i <= n; i++)
			if(a[i] && b[i]) ans = true;
	}
	printf("%s\n", ans ? "YES" : "NO");
	return 0;
}