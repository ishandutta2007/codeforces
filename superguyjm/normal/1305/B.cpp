#include <bits/stdc++.h>

#define I inline
#define fi first
#define se second
#define R register
#define LL long long
#define mp make_pair
#define reg register int
#define pii pair<int,int>
#define fo(i, a, b) for(reg i = a; i <= b; i++)
#define fd(i, a, b) for(reg i = a; i >= b; i--)
#define cr const reg&
using namespace std;

I int _max(cr x, cr y) {return x > y ? x : y;}
I int _min(cr x, cr y) {return x < y ? x : y;}
I int read() {
	reg x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	return x * f;
}
I void ptt(LL x) {if(x >= 10) ptt(x / 10); putchar(x % 10 + '0');}
I void put(LL x) {x < 0 ? putchar('-'), ptt(-x) : ptt(x);}
I void pr1(LL x) {put(x), putchar(' ');}
I void pr2(LL x) {put(x), puts("");}

char ss[1010], kk[1010];
int s1[1010], s2[1010];
bool v[1010];
vector<pair<int, vector<int>>> q; 

int main() {
	scanf("%s", ss + 1);
	reg len = strlen(ss + 1);
	while(1) {
		memset(v, 0, sizeof(v));
		reg z = 0, p;
		fo(i, 1, len) s1[i] = s1[i - 1] + (ss[i] == '(');
		s2[len + 1] = 0; fd(i, len, 1) s2[i]  = s2[i + 1] + (ss[i] == ')');
		fo(i, 1, len) {
			if(_min(s1[i], s2[i + 1]) > z) z = _min(s1[i], s2[i + 1]), p = i;
		} if(!z) break;
		vector<int> g; g.clear();
		reg y = 0;
		fo(i, 1, len) {
			if(ss[i] == '(') y++, g.push_back(i), v[i] = 1;
			if(y == z) break;
		} y = 0;
		fd(i, len, 1) {
			if(ss[i] == ')') y++, g.push_back(i), v[i] = 1;
			if(y == z) break;
		} y = 0;
		sort(g.begin(), g.end());
		fo(i, 1, len) if(!v[i]) ss[++y] = ss[i];
		q.push_back(mp(z * 2, g));
		len = y;
	} pr2((int)q.size());
	fo(i, 0, (int)q.size() - 1) {
		reg l = q[i].fi;
		pr2(l);
		fo(j, 0, l - 1) pr1(q[i].se[j]);
		puts("");
	}
	return 0;
}