#include <bits/stdc++.h>
#define maxr 100000
#define endl 1
#define maxn 600019
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

int num[maxn];
int a[maxn];
int n;
int cn = 0;

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		cn = 0;
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n){
			int now = a[i];
			cn++;
			while (i <= n && a[i] == now){
				num[cn]++;
				i++;
			}
			i--;
		}
		int mx1 = num[1], sum = num[1], f = -1;
		rep(i, 2, cn) {
			if (((sum + num[i]) << 1) <= n) sum += num[i];
			else {f = i; break;}
		}
		sum -= num[1];
		int sum2 = 0;
		srep(i, 2, f){
			sum -= num[i];
			sum2 += num[i];
			if (min(sum, sum2) > num[1]) {
				printf("%d %d %d\n", num[1], sum2, sum);
				goto jump;
			}
		}
		printf("0 0 0\n");
		jump:;
		rep(i, 1, cn) num[i] = 0;
	}
    return 0;
}