#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 3020
using namespace std;

char s[maxn];
bool vis[maxn];

int main(){
	
	int T, n;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		scanf("%s", s + 1);
		rep(i, 1, n) vis[i] = 0;
		int par = 0;
		rep(i, 1, n) if ((s[i] - '0') & 1) par ^= 1;
		int ptr = n;
		while (ptr >= 1 && (!((s[ptr] - '0') & 1))) vis[ptr--] = 1;
		if (!ptr) {printf("-1\n"); continue;}
		if (!(par & 1)) {
			rep(i, 1, ptr) printf("%c", s[i]); printf("\n");
			continue;
		}
		ptr--;
		while (ptr >= 1 && (!((s[ptr] - '0') & 1))) ptr--;
		if (!ptr) {printf("-1\n"); continue;}
		vis[ptr] = 1;
		bool lz = 1;
		rep(i, 1, n){
			if (vis[i]) continue;
			if (s[i] != '0') printf("%c", s[i]), lz = 0;
			else if (!lz) printf("%c", s[i]); 
		}
		printf("\n");
	}
	return 0;
}