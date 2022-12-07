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
#define maxn
#define maxm
#define maxs
#define maxb
#define M 
#define eps 1e-6
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

char s[25];

int restQ = 50;
int ans = -1;
bool solve(int first, int len, int nowb){ // you have determine pre-2^(nowb) from first
	int vv = (1 << nowb);
	if ((vv << 1) >= len) {
		cout << '?' << ' ' << 1 << ' ' << 1 << endl;
		cout << first << endl;
		cout << first + vv << endl;
		scanf("%s", s + 1);
		if (s[1] == 'F') {
			ans = first + vv;
			return true;
		}
		else if (s[1] == 'S'){
			return false;
		}
		else if (s[1] == 'E'){
			return solve(first + vv, len - vv, 0);
		}
		else if (s[1] == 'W'){
			return false;
		}
		return false;
	}
	else {
		cout << '?' << ' ' << vv << ' ' << vv << endl;
		rep(i, 1, vv) cout << (first + i - 1) << ' '; cout << endl;
		rep(i, vv + 1, (vv << 1)) cout << (first + i - 1) << ' '; cout << endl;
		scanf("%s", s + 1);
		if (s[1] == 'F') {
			cout << '?' << ' ' << 1 << ' ' << 1 << endl;
			cout << first << endl;
			cout << first + vv << endl;
			scanf("%s", s + 1);
			if (s[1] == 'F') {
				ans = first + vv;
				return true;
			}
			else if (s[1] == 'S'){
				return false;
			}
			else if (s[1] == 'E'){
				return solve(first + vv, vv, 0);
			}
			else if (s[1] == 'W'){
				return false;
			} 
		}
		else if (s[1] == 'S'){
			return false;
		}
		else if (s[1] == 'E'){
			return solve(first, len, nowb + 1);
		}
		else if (s[1] == 'W'){
			return false;
		}
		return false;
	}
}

int n, k;
bool judge(double eff){
	double sum = 1;
	while (sum >= eps){
		sum *= eff;
		cout << '?' << ' ' << 1 << ' ' << 1 << endl;
		cout << 1 << endl;
		cout << (rand() % (n - 1) + 2) << endl;
		scanf("%s", s + 1);
		if (s[1] == 'F') { 
			continue;
		}
		else if (s[1] == 'S'){
			return false;
		}
		else if (s[1] == 'E'){
			continue;
		}
		else if (s[1] == 'W'){
			return false;
		} 
	}
	return true;
} 

int main(){
	int T;
	cin >> T;
	while (T--){
		restQ = 50, ans = -1; 
		cin >> n >> k;
		bool res = judge(1.0 * (k - 1) / (n - 1));
		if (!res) {cout << '!' << ' ' << 1 << endl; continue;}
		if (!solve(1, n, 0)) cout << '!' << ' ' << 1 << endl;
		else cout << '!' << ' ' << ans << endl;
	} 
	return 0;
}