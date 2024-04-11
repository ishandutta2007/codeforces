#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 200020
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

int n, k;
char s[maxn];
int num[26];

int main(){
	//freopen("C.in", "r", stdin);
	int T;
	scanf("%d", &T);
	rep(TT, 1, T){
		rep(i, 0, 25) num[i] = 0;
		scanf("%d%d", &n, &k);
		scanf("%s", s + 1);
		rep(i, 1, n) num[s[i] - 'a']++;
		int mx = -1;
		per(i, 25, 0) if (num[i]) {mx = i; break;} 
		int ptr = 0, sum = num[0];
		while (sum < k) {
			ptr++;
			sum += num[ptr];
		}
		printf("%c", 'a' + ptr);
		int _k = k;
		bool f = 0;
		srep(i, 0, ptr) if (num[i]) {f = 1; break;} 
		while (k){
			if (k > num[ptr]) k -= num[ptr], num[ptr] = 0, ptr--;
			else num[ptr] -= k, k = 0; 
		}
		int cnt = 0;
		if (f) goto over;
		else {
			rep(i, 0, 25) if (num[i]) cnt++; 
			if (cnt == 1){
				rep(i, 0, 25){
					if (num[i]){
						rep(j, 1, (num[i] - 1) / _k + 1) printf("%c", 'a' + i);
						goto over;
					}
				}
			}
			else {
				rep(i, 0, 25) rep(j, 1, num[i]) printf("%c", 'a' + i); 
			}
		}
		over:printf("\n");
	}
	return 0;
}