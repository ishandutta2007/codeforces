// LUOGU_RID: 90296411
//0720T2
//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e6+5, B = 10, P = 1e9-63;

int n;
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct StringHash {
	int hsh[N], pw[N];
	void init(char* s, int n) {
		pw[0] = 1;
		rep(i, 1, n) {
			hsh[i] = (1LL * hsh[i-1] * B % P + s[i] - 48) % P;
			pw[i] = 1LL * pw[i-1] * B % P;
		}
	}
	int getHash(int l, int r) {
		int ans = (hsh[r] - 1LL * hsh[l-1] * pw[r-l+1] % P + P) % P;
		return ans;
	}
}h;
bool check(int i, int j) { // [1, i] [i+1, j] [j+1, n]
	if(i < 1 || j < i + 1 || n < j + 1) return 0;
	int x = h.getHash(1, i), y = h.getHash(i+1, j), z = h.getHash(j+1, n);
	if(i > 1 && s[1] == '0') return 0;
	if(j > i + 1 && s[i+1] == '0') return 0;
	if(n > j + 1 && s[j+1] == '0') return 0;
	if((x + y) % P != z) return 0;
	return 1;
}
void giveAns(int i, int j) {
//	printf("%d %d\n", i, j);
	rep(x, 1, i) putchar(s[x]);
	putchar('+');
	rep(x, i+1, j) putchar(s[x]);
	putchar('=');
	rep(x, j+1, n) putchar(s[x]);
}

int main() {
// 	fileIO("hash2");
	scanf("%s", s+1);
	n = strlen(s+1);
	h.init(s, n);
	rep(len, 1, n) {
		if(check(len-1, n-len)) {
			giveAns(len-1, n-len);
			return 0;
		}
		else if(check(len, n-len)) {
			giveAns(len, n-len);
			return 0;
		}
		else if(check(len+1, n-len)) {
			giveAns(len+1, n-len);
			return 0;
		}
		else if(check(n-2*len-1, n-len)) {
			giveAns(n-2*len-1, n-len);
			return 0;
		}
		else if(check(n-2*len, n-len)) {
			giveAns(n-2*len, n-len);
			return 0;
		}
		else if(check(n-2*len+1, n-len)) {
			giveAns(n-2*len+1, n-len);
			return 0;
		}
	}
	return 0;
}