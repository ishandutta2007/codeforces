#include <bits/stdc++.h>
#define maxr 100000
#define endl 1
#define maxn 200019
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

int num[maxn];
int cn = 0;

int main(){
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int n = a + b + c + d;
	if (b < a){
		if (c == 0 && d == 0 && a - b == 1){
			printf("YES\n");
			printf("0"); for (register int i = 2; i <= n; i += 2) printf(" 1 0");
			return 0;
		}
		printf("NO");
		return 0;
	}
	if (c < d){
		if (a == 0 && b == 0 && d - c == 1){
			printf("YES\n");
			printf("3"); for (register int i = 2; i <= n; i += 2) printf(" 2 3");
			return 0;
		}
		printf("NO");
		return 0;
	}
	b -= a, c -= d;
	if (b - c == 1){
		num[1] = 1;
		int i = 1;
		while (a){
			num[++i] = 0, num[++i] = 1;
			a--;
		}
		int l = i + 1;
		i = n + 1;
		while (d){
			num[--i] = 3, num[--i] = 2;
			d--;
		}
		int r = i - 1;
		for (register int i = l; i <= r; i += 2){
			num[i] = 2, num[i + 1] = 1;
		}
		printf("YES\n");
		rep(i, 1, n) printf("%d ", num[i]);
		return 0;
	}
	else if (b == c){
		int i = 0;
		while (a){
			num[++i] = 0, num[++i] = 1;
			a--;
		}
		int l = i + 1;
		i = n + 1;
		while (d){
			num[--i] = 3, num[--i] = 2;
			d--;
		}
		int r = i - 1;
		for (register int i = l; i <= r; i += 2){
			num[i] = 2, num[i + 1] = 1;
		}
		printf("YES\n");
		rep(i, 1, n) printf("%d ", num[i]);
		return 0;
	}
	else if (b - c == -1){
		int i = 0;
		while (a){
			num[++i] = 0, num[++i] = 1;
			a--;
		}
		int l = i + 1;
		num[n] = 2;
		i = n;
		while (d){
			num[--i] = 3, num[--i] = 2;
			d--;
		}
		int r = i - 1;
		for (register int i = l; i <= r; i += 2){
			num[i] = 2, num[i + 1] = 1;
		}
		printf("YES\n");
		rep(i, 1, n) printf("%d ", num[i]);
		return 0;
	}
	else {
		printf("NO");
		return 0;
	}
    return 0;
}