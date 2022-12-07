#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 400020
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
bool play(){
	int num0 = 0, num1 = 0, num2 = 0;
	rep(i, 1, k) {
		if (s[i] == '0') num0++;
		else if (s[i] == '1') num1++;
		else num2++;
	} 
	rep(i, 1, n) {
		if (min(num0, num1) + num2 < max(num0, num1)) { 
			return false;
		}
		if (s[i] == '0') num0--;
		else if (s[i] == '1') num1--;
		else num2--;
		
		if (i + k > n) break;
		if (s[i + k] == '0') num0++;
		else if (s[i + k] == '1') num1++;
		else num2++;
	}
	return true;
}
int main(){
	int T; scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &k);
		scanf("%s", s + 1);
		bool f = 1; int now = -1, i, j;
		
		if (!play()) {
			f = 0;
			goto done;
		}  
		for (i = 1; i <= k; i++){
			now = -1;
			for (j = i; j <= n; j += k) {
				if (s[j] != '?') {
					if (now == -1) now = s[j] - '0';
					else if (now != s[j] - '0') {
						f = 0;
						goto done;
					} 
				} 
			}
			if (now != -1) {
				for (j = i; j <= n; j += k) {
					if (s[j] == '?') s[j] = '0' + now; 
				}
			} 
		}
		if (!play()) {
			f = 0;
			goto done;
		}
		done:;
		if (f) printf("YES\n");
		else printf("NO\n");
	} 
	return 0;
}