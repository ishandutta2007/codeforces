#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%I64d"
#endif
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash

typedef long long ll;
typedef long long llong;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 10;
const int LEN = 50 * 1000;
const int X1 = 4243;
const int X2 = 10007;
const int MOD1 = int(1e9) + 7;
const int MOD2 = 42424243;
const int LOG = 16;

struct hash{
	int h1, h2;
	
	hash(){}
	
	hash(int _h1, int _h2){
		h1 = _h1;
		h2 = _h2;
	}
	
};

hash operator + (const hash &a, const hash &b){
	hash c(a.h1 + b.h1, a.h2 + b.h2);
	if(c.h1 >= MOD1){
		c.h1 -= MOD1;
	}
	if(c.h2 >= MOD2){
		c.h2 -= MOD2;
	}
	return c;
}

hash operator - (const hash &a, const hash &b){
	hash c(a.h1 - b.h1, a.h2 - b.h2);
	if(c.h1 < 0){
		c.h1 += MOD1;
	}
	if(c.h2 < 0){
		c.h2 += MOD2;
	}
	return c;
}

hash operator * (const hash &a, const hash &b){
	return hash((ll(a.h1) * b.h1) % MOD1, (ll(a.h2) * b.h2) % MOD2);
}

bool operator == (const hash &a, const hash &b){
	return a.h1 == b.h1 && a.h2 == b.h2;
}

struct elem{
	int start, gl, gr;
	
	elem(){}
	
	elem(int _start, int _gl, int _gr){
		start = _start;
		gl = _gl;
		gr = _gr;
	}
	
};

struct ta{
	int start, col1, col2;
};

int NUM, ptr;
hash X(X1, X2);
int l[N + 2], r[N + 2], len[N + 2];
char s[N + 2][LEN + 100];
hash h[N + 2][LEN + 100];
hash p[LEN + 100];
int perm[N + 2][LEN + 100];
elem lst[LEN + 100];
int lval[LOG + 2][2 * LEN + 100], rval[LOG + 2][2 * LEN + 100];
int lg[LEN + 100][N + 2], rg[LEN + 100][N + 2];
int sum[2 * LEN + 100];
int link[LEN + 100];
pii S[2 * LEN + 100];
char tmp[LEN + 100];
int col[LEN + 100];
ta a[LEN + 100], b[LEN + 100];

inline hash get_h(hash *h, int l, int r){
	hash res = h[r] - (l > 0 ? h[l - 1] : hash(0, 0));
	res = res * p[LEN - l];
	return res;
}

inline int get_lcp(int num1, int pos1, int num2, int pos2){
	int res = 0, l = 1, r = min(len[num1] - pos1, len[num2] - pos2);
	while(l <= r){
		int mid = (l + r) / 2;
		if(get_h(h[num1], pos1, pos1 + mid - 1) == get_h(h[num2], pos2, pos2 + mid - 1)){
			res = mid;
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	return res;
}

inline bool cmp(int a, int b){
	int res = get_lcp(NUM, a, NUM, b);
	if(res == len[NUM] - b){
		return false;
	}
	if(res == len[NUM] - a){
		return true;
	}
	return s[NUM][a + res] < s[NUM][b + res];
}

inline bool cmp_lst(const elem &a, const elem &b){
	int res = 0, l = 1, r = min(a.gr - a.start + 1, b.gr - b.start + 1);
	while(l <= r){
		int mid = (l + r) / 2;
		if(get_h(h[NUM], a.start, a.start + mid - 1) == get_h(h[NUM], b.start, b.start + mid - 1)){
			res = mid;
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	if(res == b.gr - b.start + 1){
		return false;
	}
	if(res == a.gr - a.start + 1){
		return true;
	}
	return s[NUM][a.start + res] < s[NUM][b.start + res];
}

inline int get_sum(int l, int r){
	return sum[r] - (l > 0 ? sum[l - 1] : 0);
}

inline int calc(int l, int r){
	int pos = link[l], cur = pos - 1;
	for(int i = LOG; i >= 0; i--){
		if(cur - (1 << i) + 1 >= 0 && lval[i][cur] >= r - l + 1){
			cur -= (1 << i);
		}
	}
	int res = get_sum(cur + 1, pos);
	cur = pos + 1;
	for(int i = LOG; i >= 0; i--){
		if(cur + (1 << i) - 1 < ptr && rval[i][cur] >= r - l + 1){
			cur += (1 << i);
		}
	}
	res += get_sum(pos, cur - 1);
	return res;
}

inline bool cmp_ext(int num1, int pos1, int num2, int pos2){
	int res = get_lcp(num1, pos1, num2, pos2);
	if(res == len[num2] - pos2){
		return false;
	}
	if(res == len[num1] - pos1){
		return true;
	}
	return s[num1][pos1 + res] < s[num2][pos2 + res];
}

inline int get_lcp_ext(elem &a, elem &b){
	int res = 0, l = 1, r = min(a.gr - a.start + 1, b.gr - b.start + 1);
	while(l <= r){
		int mid = (l + r) / 2;
		if(get_h(h[NUM], a.start, a.start + mid - 1) == get_h(h[NUM], b.start, b.start + mid - 1)){
			res = mid;
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	return res;
}

inline void gen(){
	freopen("input.txt", "w", stdout);
	for(int i = 0; i < 50000; i++){
		cout << char('a' + rand() % 26);
	}
	cout << endl;
	cout << 10 << endl;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 50000; j++){
			cout << char('a' + rand() % 26);
		}
		cout << " " << rand() % 10 << " " << rand() % 10 << endl;
	}
	exit(0);
}

int main(){
	//gen();
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", tmp);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s %d %d", s[i], &l[i], &r[i]);
		len[i] = strlen(s[i]);
	}
	strcpy(s[n], tmp);
	len[n] = strlen(s[n]);
	p[0] = hash(1, 1);
	for(int i = 1; i <= LEN; i++){
		p[i] = p[i - 1] * X;
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < len[i]; j++){
			h[i][j] = (j > 0 ? h[i][j - 1] : hash(0, 0)) + p[j] * hash(s[i][j], s[i][j]);
		}
	}
	for(int i = 0; i <= n; i++){
		s[i][len[i]] = 'a' - 1;
		for(int j = 0; j <= len[i]; j++){
			a[j].start = j;
			a[j].col1 = s[i][j] - 'a' + 1;
			a[j].col2 = 0;
		}
		int maxv = 1;
		while(maxv < len[i] + 1){
			maxv *= 2;
		}
		int k = 1;
		while(k <= maxv){
			for(int j = 0; j <= max(len[i], 100); j++){
				col[j] = 0;
			}
			for(int j = 0; j <= len[i]; j++){
				col[a[j].col1]++;
			}
			for(int j = 1; j <= max(len[i], 100); j++){
				col[j] += col[j - 1];
			}
			for(int j = len[i]; j >= 0; j--){
				b[--col[a[j].col1]] = a[j];
			}
			for(int j = 0; j <= len[i]; j++){
				a[j] = b[j];
			}
			if(k == maxv){
				break;
			}
			int cur = 0;
			for(int j = 0; j <= len[i]; j++){
				if(j > 0 && (a[j - 1].col1 != a[j].col1 || a[j - 1].col2 != a[j].col2)){
					cur++;
				}
				col[a[j].start] = cur;
			}
			for(int j = 0; j <= len[i]; j++){
				a[j].col2 = col[a[j].start];
				a[j].start -= k;
				if(a[j].start < 0){
					a[j].start += len[i] + 1;
				}
				a[j].col1 = col[a[j].start];
			}
			k *= 2;
		}
		for(int j = 0; j < len[i]; j++){
			perm[i][j] = a[j + 1].start;
		}
	}
	if(n == 0){
		ll ans = 0;
		for(int i = 0; i < len[0]; i++){
			ans += len[0] - perm[0][i];
			if(i > 0){
				ans -= get_lcp(0, perm[0][i - 1], 0, perm[0][i]);
			}
		}
		printf(LLD"\n", ans);
		return 0;
	}
	for(int i = 0; i < n; i++){
		int j = 0, z = 0;
		ptr = 0;
		while(j < len[i] && z < len[n]){
			if(cmp_ext(i, perm[i][j], n, perm[n][z])){
				S[ptr++] = mp(i, perm[i][j++]);
			}
			else{
				S[ptr++] = mp(n, perm[n][z++]);
			}
		}
		while(j < len[i]){
			S[ptr++] = mp(i, perm[i][j++]);
		}
		while(z < len[n]){
			S[ptr++] = mp(n, perm[n][z++]);
		}
		for(int j = 0; j < ptr; j++){
			if(S[j].fs == n){
				link[S[j].sc] = j;
			}
		}
		for(int j = 0; j < ptr - 1; j++){
			lval[0][j] = get_lcp(S[j].fs, S[j].sc, S[j + 1].fs, S[j + 1].sc);
		}
		for(int j = 1; j <= LOG; j++){
			for(int z = 0; z < ptr; z++){
				if(z - (1 << j) + 1 >= 0){
					lval[j][z] = min(lval[j - 1][z], lval[j - 1][z - (1 << (j - 1))]);
				}
			}
		}
		for(int j = 1; j < ptr; j++){
			rval[0][j] = get_lcp(S[j - 1].fs, S[j - 1].sc, S[j].fs, S[j].sc);
		}
		for(int j = 1; j <= LOG; j++){
			for(int z = 0; z < ptr; z++){
				if(z + (1 << j) - 1 < ptr){
					rval[j][z] = min(rval[j - 1][z], rval[j - 1][z + (1 << (j - 1))]);
				}
			}
		}
		for(int j = 0; j < ptr; j++){
			sum[j] = (j > 0 ? sum[j - 1] : 0) + (S[j].fs == i);
		}
		int lptr = 0, rptr = 0;
		for(int j = 0; j < len[n]; j++){
			lptr = max(lptr, j);
			rptr = max(rptr, j);
			while(lptr < len[n] && calc(j, lptr) > r[i]){
				lptr++;
			}
			while(rptr + 1 < len[n] && calc(j, rptr + 1) >= l[i]){
				rptr++;
			}
			if(lptr < len[n] && calc(j, lptr) <= r[i] && calc(j, rptr) >= l[i] && lptr <= rptr){
				lg[j][i] = lptr;
				rg[j][i] = rptr;
			}
			else{
				lg[j][i] = rg[j][i] = -1;
			}
		}
	}
	/*for(int i = 0; i < len[n]; i++){
		cerr << "FOR " << i << endl;
		for(int j = 0; j < n; j++){
			cerr << lg[i][j] << " " << rg[i][j] << endl;
		}
	}*/
	int sz = 0;
	for(int i = 0; i < len[n]; i++){
		bool good = true;
		for(int j = 0; j < n; j++){
			if(lg[i][j] == -1){
				good = false;
				break;
			}
		}
		if(!good){
			continue;
		}
		int gl = -inf, gr = inf;
		for(int j = 0; j < n; j++){
			gl = max(gl, lg[i][j]);
			gr = min(gr, rg[i][j]);
		}
		if(gl > gr){
			continue;
		}
		lst[sz++] = elem(i, gl, gr);
	}
	NUM = n;
	sort(lst, lst + sz, cmp_lst);
	ll ans = 0;
	for(int i = 0; i < sz; i++){
		ans += lst[i].gr - lst[i].gl + 1;
		if(i > 0){
			int lcp = get_lcp_ext(lst[i - 1], lst[i]);
			if(lst[i].start + lcp - 1 <= lst[i].gr){
				if(lst[i].start + lcp - 1 >= lst[i].gl){
					ans -= lst[i].start + lcp - lst[i].gl;
				}
			}
		}
	}
	printf(LLD"\n", ans);
	return 0;
}