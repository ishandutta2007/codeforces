#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 1001000;
int a[maxn], f[maxn], st[maxn];
bool Up(int y, int x){
	long long a = (1ll*st[y]*st[y]+1ll*st[y+1]*st[y+1])*st[x]*st[x+1];
	long long b = (1ll*st[x]*st[x]+1ll*st[x+1]*st[x+1])*st[y]*st[y+1];
	return a < b;
}
int main(){
	int T; scanf("%d", &T);
	while(T--){
		int n; scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		int tp = 0;
		for(int i = 1; i <= n; i++){
			if(f[a[i]]) st[++tp] = a[i];
			f[a[i]] ^= 1;
		}
		sort(st + 1, st + 1 + tp);
		int x = 1;
		for(int i = 1; i < tp; i++)
			if(Up(i, x))
				x = i;
		printf("%d %d %d %d\n", st[x], st[x], st[x+1], st[x+1]);
		for(int i = 1; i <= n; i++)
			f[a[i]] = false;
	}
	return 0;
}