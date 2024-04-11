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
#define len(s) int((s).size())
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

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned long long lint;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5);
const int LOG = 17;
const int X1 = 4243;
const int X2 = int(1e4) + 7;
const int MOD1 = int(1e9) + 7;
const int MOD2 = 42424243;

/*struct hash{
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
}*/

typedef long long hash;

hash X = 203;
int len[LOG + 10];
ll len2[LOG + 10];
int cnt[26][N + 10], prev[N + 10][26], next[N + 10][26];
int last[30];
ll add[30];
char s[N + 10];
ll pref[N + 10], suff[N + 10];
bool good[LOG + 10][N + 10];
hash h[N + 10], p[N + 10];

inline ll sqr(ll a){
	return a * a;
}

inline int get_cnt(int *cnt, int l, int r){
	return cnt[r] - (l > 0 ? cnt[l - 1] : 0);
}

inline hash get_h(int l, int r){
	return h[r] - (l > 0 ? (h[l - 1] * p[r - l + 1]) : 0);
}

int main(){
	gets(s);
	int n = strlen(s);
	p[0] = 1;
	for(int i = 1; i <= n; i++){
		p[i] = p[i - 1] * X;
	}
	for(int i = 0; i < n; i++){
		h[i] = (i > 0 ? h[i - 1] : 0) * X + s[i];
	}
	for(int i = 0; i < LOG; i++){
		len[i] = (1 << (i + 1)) - 1;
		len2[i] = sqr(len[i]);
	}
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < n; j++){
			cnt[i][j] = (j > 0 ? cnt[i][j - 1] : 0) + (s[j] - 'a' == i);
		}
	}
	for(int i = 0; i < LOG; i++){
		for(int j = 0; j < n; j++){
			if(j - len[i] / 2 < 0 || j + len[i] / 2 >= n){
				continue;
			}
			if(i == 0){
				good[i][j] = true;
			}
			else{
				if(get_cnt(cnt[s[j] - 'a'], j - len[i] / 2, j + len[i] / 2) == 1 && get_h(j - len[i] / 2, j - 1) == get_h(j + 1, j + len[i] / 2)){
					if(good[i - 1][(j - len[i] / 2 + j - 1) / 2]){
						good[i][j] = true;
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(i > 0){
			pref[i] += pref[i - 1];
		}
		for(int j = 0; ; j++){
			if(i - len[j] + 1 < 0){
				break;
			}
			if(good[j][i - len[j] / 2]){
				pref[i] += len2[j];
			}
		}
	}
	for(int i = n - 1; i >= 0; i--){
		if(i + 1 < n){
			suff[i] += suff[i + 1];
		}
		for(int j = 0; ; j++){
			if(i + len[j] - 1 >= n){
				break;
			}
			if(good[j][i + len[j] / 2]){
				suff[i] += len2[j];
			}
		}
	}
	for(int i = 0; i < 26; i++){
		last[i] = -1;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 26; j++){
			prev[i][j] = last[j];
		}
		last[s[i] - 'a'] = i;
	}
	for(int i = 0; i < 26; i++){
		last[i] = -1;
	}
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < 26; j++){
			next[i][j] = last[j];
		}
		last[s[i] - 'a'] = i;
	}
	ll ans = pref[n - 1];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 26; j++){
			add[j] = 0;
		}
		for(int j = 0; j < 26; j++){
			if(prev[i][j] != -1){
				int pos = prev[i][j];
				for(int z = 1; ; z++){
					if(pos - len[z] / 2 < 0 || pos + len[z] / 2 >= n){
						break;
					}
					if(pos + len[z] / 2 < i){
						continue;
					}
					if(get_cnt(cnt[s[pos] - 'a'], pos - len[z] / 2, pos + len[z] / 2) - (s[i] == s[pos]) > 1){
						break;
					}
					int ri = pos - 1 - (pos + len[z] / 2 - i);
					hash h1 = get_h(pos - len[z] / 2, pos - 1) - s[ri] * p[len[z] / 2 - (ri - (pos - len[z] / 2)) - 1];
					hash h2 = get_h(pos + 1, pos + len[z] / 2) - s[i] * p[len[z] / 2 - (i - (pos + 1)) - 1];
					if(h1 == h2 && good[z - 1][(pos - len[z] / 2 + pos - 1) / 2]){
						add[s[ri] - 'a'] += len2[z];
					}
					else{
						break;
					}
				}
			}
			if(next[i][j] != -1){
				int pos = next[i][j];
				for(int z = 1; ; z++){
					if(pos - len[z] / 2 < 0 || pos + len[z] / 2 >= n){
						break;
					}
					if(pos - len[z] / 2 > i){
						continue;
					}
					if(get_cnt(cnt[s[pos] - 'a'], pos - len[z] / 2, pos + len[z] / 2) - (s[pos] == s[i]) > 1){
						break;
					}
					int ri = pos + len[z] / 2 - (pos - 1 - i);
					hash h1 = get_h(pos - len[z] / 2, pos - 1) - s[i] * p[len[z] / 2 - (i - (pos - len[z] / 2)) - 1];
					hash h2 = get_h(pos + 1, pos + len[z] / 2) - s[ri] * p[len[z] / 2 - (ri - (pos + 1)) - 1];
					if(h1 == h2 && good[z - 1][(pos + 1 + pos + len[z] / 2) / 2]){
						add[s[ri] - 'a'] += len2[z];
					}
					else{
						break;
					}
				}
			}
		}
		for(int j = 0; j < 26; j++){
			for(int z = 0; ; z++){
				if(i - len[z] / 2 < 0 || i + len[z] / 2 >= n){
					break;
				}
				if(get_cnt(cnt[j], i - len[z] / 2, i + len[z] / 2) - (s[i] - 'a' == j) > 0){
					break;
				}
				if(z == 0 || (get_h(i - len[z] / 2, i - 1) == get_h(i + 1, i + len[z] / 2) && good[z - 1][(i - len[z] / 2 + i - 1) / 2])){
					add[j] += len2[z];
				}
			}
		}
		for(int j = 0; j < 26; j++){
			ll res = (i > 0 ? pref[i - 1] : 0) + (i + 1 < n ? suff[i + 1] : 0) + add[j];
			ans = max(ans, res);
		}
	}
	printf(LLD"\n", ans);
	return 0;
}