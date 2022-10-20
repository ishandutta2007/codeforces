#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
typedef unsigned long long ull;
template<typename T> inline void gi(T &x){
	char ch; x = 0;
	int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}

const int N = 200005;
const ull p1 = 999983, p2 = 10007, mod1 = 104857601, mod2 = 167772161;
char s[N];
int cnt[N];

template<ull p, ull mod>
struct Hash{
	ull h[N], pw[N];
	int len;
	Hash(){pw[0] = 1; len = 0; h[0] = 0;}
	void hash(ull x){
		++len;
		pw[len] = pw[len - 1] * p % mod;
		h[len] = (h[len - 1] + x * pw[len]) % mod;
	}
	void space(){
		++len;
		h[len] = h[len - 1];
		pw[len] = pw[len - 1];
	}
	ull ask(int l, int r){
		return (h[r] - h[l - 1] + mod) % mod;
	}
};
Hash<p1, mod1> h01, h11;
Hash<p2, mod2> h02, h12;

int main(){
	// File("cf1320d");
	int n;
	gi(n);
	scanf("%s", s + 1);
	for(int i=1; i<=n; i++){
		if(s[i] == '1'){
			h01.space(); h11.space(); h02.space(); h12.space();
			cnt[i] = cnt[i-1];
		}
		else{
			h01.hash((i & 1) + 1); h02.hash((i & 1) + 1);
			h11.hash(((i & 1) ^ 1) + 1); h12.hash(((i & 1) ^ 1) + 1);
			cnt[i] = cnt[i-1] + 1;
		}
	}
	int q; gi(q);
	while(q--){
		int _l, _r, _len;
		gi(_l); gi(_r); gi(_len);
		int l1, r1, l2, r2;
		l1 = _l; r1 = _l  + _len - 1; l2 = _r; r2 = _r + _len - 1;
		if((cnt[r1] - cnt[l1 - 1]) != (cnt[r2] - cnt[l2 - 1])){
			puts("No");
			continue;
		}
		if((l1 ^ l2) & 1){
			ull h1 = h01.ask(l1, r1) * h11.pw[l2 - 1] % mod1;
			ull h2 = h11.ask(l2, r2) * h01.pw[l1 - 1] % mod1;
			if(h1 != h2){
				puts("No");
				continue;
			}
			h1 = h02.ask(l1, r1) * h12.pw[l2 - 1] % mod2;
			h2 = h12.ask(l2, r2) * h02.pw[l1 - 1] % mod2;
			if(h1 != h2){
				puts("No");
				continue;
			}
		}
		else{
			ull h1 = h01.ask(l1, r1) * h01.pw[l2 - 1] % mod1;
			ull h2 = h01.ask(l2, r2) * h01.pw[l1 - 1] % mod1;
			if(h1 != h2){
				puts("No");
				continue;
			}
			h1 = h02.ask(l1, r1) * h02.pw[l2 - 1] % mod2;
			h2 = h02.ask(l2, r2) * h02.pw[l1 - 1] % mod2;
			if(h1 != h2){
				puts("No");
				continue;
			}
		}
		puts("Yes");
	}
	return 0;
}
//