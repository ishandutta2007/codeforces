#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(a) (a)*(a)

typedef long long int64;
typedef pair<int,int> pii;

const int inf = (int)1E+9;
const double eps = 1e-9;

const string task = "a";
const string inp = task + ".in";
const string oup = task + ".out";

const int MLEN = 1000;
const int BASE = 1000;// * 1000 * 1000;
const int DIG  = 3;

struct tlong{
	int len, dig[MLEN];

	tlong () {
		len = 1;
		memset(dig, 0, sizeof dig);
	}

	inline void norm () {
		while (len > 0 && dig[len-1] == 0) len --;
	}

	inline void write () {
		if (len == 0)
			dig[len++] = 0;
		printf("%d", dig[len-1]);
		ford(i,len-1)
			printf("%03d", dig[i]);
		printf("\n");
	}

	inline void init(long long x) {
		len = 0;
		memset(dig, 0, sizeof dig);
		do{
			dig[len ++] = x % BASE;
			x /= BASE;
		} while (x > 0);
	}
			

	inline tlong (int x) {
		init (x);
	}

	inline tlong (long long x) {
		init (x);
	}

	inline tlong (const string &s) {
		len = 0;
		memset(dig, 0, sizeof dig);
		int now = 0;
		long long st = 1;
		ford(i,s.size()){
			if (now == DIG){
				len ++;
				now = 0;
				st = 1;
			}
			dig[len] = dig[len] + st * (s[i] - '0');
			st = st * 10;
			now ++;
		}
		len ++;
		norm ();

	}

	inline bool operator < (const tlong &b) {
		if (len != b.len) return len < b.len;
		ford(i,len)
			if (dig[i] != b.dig[i])
				return dig[i] < b.dig[i];
		return 0;
	}

	inline bool operator <= (const tlong &b) {
		if (len != b.len) return len < b.len;
		ford(i,len)
			if (dig[i] != b.dig[i])
				return dig[i] < b.dig[i];
		return 1;
	}

	inline bool operator > (const tlong &b) {
		if (len != b.len) return len > b.len;
		ford(i,len)
			if (dig[i] != b.dig[i])
				return dig[i] > b.dig[i];
		return 0;
	}

	inline bool operator >= (const tlong &b) {
		if (len != b.len) return len > b.len;
		ford(i,len)
			if (dig[i] != b.dig[i])
				return dig[i] > b.dig[i];
		return 1;
	}

	inline bool operator == (const tlong &b) {
		if (len != b.len) return 0;
		ford(i,len)
			if (dig[i] != b.dig[i])
				return 0;
		return 1;
	}

	inline tlong operator + (const tlong &b) {
		tlong res = b;
		res.len = max(res.len, len) + 1;
		forn(i,len){
			res.dig[i] += dig[i];
			if (res.dig[i] >= BASE){
				res.dig[i] -= BASE;
				res.dig[i+1] ++;
			}
		}
		res.norm();
		return res;
	}

	inline tlong operator - (const tlong &b) {
		tlong res = *this;
		assert (res >= b);
		forn(i,res.len){
			if (i < b.len)
				res.dig[i] = res.dig[i] - b.dig[i];
			if (res.dig[i] < 0){
				res.dig[i] += BASE;
				res.dig[i+1] --;
			}
		}
		res.norm();
		return res;
	}

	inline tlong operator * (const tlong &b) {
		tlong res;
		res.len = len + b.len + 1;
		forn(i,len)
			forn(j,b.len){
				long long now = 1ll * res.dig[i+j] + 1ll * dig[i] * b.dig[j];
				res.dig[i+j] = now % BASE;
				res.dig[i+j+1] += now / BASE;
			}
		res.norm();
		return res;
	}
};

int n;
pii sel[10010];
int have[10100];
bool used[10000];
bool ad[3000];



int main(){
//	freopen(inp.data(), "rt", stdin);
//	freopen(oup.data(),"wt", stdout);

	cin >> n;
	memset(sel, 255, sizeof sel);
	memset(have, 255, sizeof have);
	forn(i,n){
		string s;
		int x;
		cin >> s >> x;
		if (s == "sell")
			sel[x] = mp(have[x],i);
		else
			have[x] = i;
	}

	ford(i,2001)
		if (sel[i].fs >= 0){
			bool gd = 1;
			for (int j = sel[i].fs; j <= sel[i].sc; j++)
				gd = gd & (!used[j]);
			if (!gd) continue;
			for (int j = sel[i].fs; j <= sel[i].sc; j++)
				used[j] = 1;
			ad[i] = 1;
		}
	tlong now,res;
	now = 1;
	for (int i = 0; i <= 2000; i++){
		if (ad[i])
			res = res + now;
		now = now * 2;
	}
	res.write();
		



	return 0;
}