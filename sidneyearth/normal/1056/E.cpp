#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000100;
const int M = 27;
const ll MOD = 1e9 + 7;
ll h[maxn], f[maxn];
int r[30], n, m;
char s[maxn], t[maxn];
ll Hash(int l, int r){
	return (h[r] - h[l] * f[r - l] % MOD + MOD) % MOD;
}
bool IsAns(ll vz, ll vo, int lz, int lo){
	for(int i = 1, l = 0; i <= n; i++){
		if(s[i] == '0'){
			if(Hash(l, l + lz) != vz) return false;
			l += lz;
		}
		else{
			if(Hash(l, l + lo) != vo) return false;
			l += lo;
		}
	}
	return true;
}
int main(){
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1); m = strlen(t + 1);
	for(int i = 0; i <= m; i++) f[i] = i == 0 ? 1 : f[i-1] * M % MOD;
	for(int i = 0; i < 26; i++) r[i] = i;
	random_shuffle(r, r + 26);
	for(int i = 1; i <= m; i++) t[i] = 'a' + r[t[i] - 'a'];
	for(int i = 1; i <= m; i++)
		h[i] = (h[i-1] * M + t[i] - 'a' + 1) % MOD;
	int ans = 0;
	int pz = 0, po = 0, cz = 0, co = 0;
	for(int i = 1; i <= n; i++){
		if(s[i] == '0'){
			if(!pz) pz = i;
			cz++;
		}
		else{
			if(!po) po = i;
			co++;
		}
	}
	for(int lz = 1; lz <= (m - 1) / cz; lz++){
		if((m - lz * cz) % co) continue;
		int lo = (m - lz * cz) / co;
		ll vz = Hash((pz-1)*lo, (pz-1)*lo+lz);
		ll vo = Hash((po-1)*lz, (po-1)*lz+lo);
		if(vz == vo) continue;
		ans += IsAns(vz, vo, lz, lo);
	}
	printf("%d\n", ans);
	return 0;
}