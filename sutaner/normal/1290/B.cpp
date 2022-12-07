#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define lowbit(x) (x & -x)
#define pb push_back
#define maxn 200020
#define maxm 
#define M 
using namespace std;

int n, m;
char s[maxn];
int num[maxn][26];

int main(){
	
		//freopen("B.in", "r", stdin);
	
	int x, y;
	scanf("%s", s + 1);
	n = strlen(s + 1);
	rep(i, 1, n){
		rep(j, 0, 25) num[i][j] = num[i - 1][j];
		num[i][s[i] - 'a']++;
	}
	scanf("%d", &m);
	rep(i, 1, m){
		scanf("%d%d", &x, &y);
		if (x == y) printf("Yes\n");
		else {
			if (s[x] != s[y]) printf("Yes\n");
			else {
				int ct = 0;
				rep(j, 0, 25) if (num[y][j] != num[x - 1][j]) ct++;
				if (ct <= 2) printf("No\n");
				else printf("Yes\n");
			}
		}
	}
	return 0;
}