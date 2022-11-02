#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int n, ans[maxn];
char s[maxn], t[maxn], q[maxn];
int Pos(int k){
	for(int i = 1; i <= n - k + 1; i++){
		if(s[i] == t[k]) return i;
	}
	return -1;
}
void Shift(int k){
	for(int i = n - k + 1, j = n; i < j; i++, j--)
		swap(s[i], s[j]);
	for(int i = 1; i <= n; i++)
		q[(i + k - 1) % n + 1] = s[i];
	for(int i = 1; i <= n; i++)
		s[i] = q[i];
//	printf("%d %s\n", k, s + 1);
}
int Solve(){
	int rnt = 0;
	for(int i = 1; i <= n; i++){
		int p = Pos(i);
//		printf("i:%d p:%d\n", i, p);
		if(p == -1) return -1;
		Shift(n - p);
		Shift(1);
		Shift(n);
		ans[rnt++] = n - p;
		ans[rnt++] = 1;
		ans[rnt++] = n;
	}
	return rnt;
}
int main(){
	scanf("%d", &n);
	scanf("%s%s", s + 1, t + 1);
	int cnt = Solve();
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}