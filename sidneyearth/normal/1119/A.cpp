#include <stdio.h>
#include <algorithm>
using namespace std;
int a[300100];
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int l, r, ans = -1;
	for(int i = 1; i <= n; ++i)
		if(a[i] != a[1]){
			l = i;
			break;
		}
	for(int i = n; i > 0; --i)
		if(a[i] != a[n]){
			r = i;
			break;
		}
	if(a[1] != a[n]) ans = max(ans, n - 1);
	if(a[1] != a[r]) ans = max(ans, r - 1);
	if(a[l] != a[n]) ans = max(ans, n - l);
	if(a[l] != a[r]) ans = max(ans, r - l);
	printf("%d\n", ans);
	return 0;
}