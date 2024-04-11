#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	char ch; x = 0;
	// int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}

const int N = 105;
const ll P = 999983, add = 10007, mod = 19260817, mask = (1<<15) - 1;
vector<int> val[mod + 5];
int a[N], b[N];
int pc[mask + 5];
int n;

bool check(int high, int low){
	//printf("check %d %d\n", high, low);
	int last = 0;
	for(int i=1; i<=n; i++){
		int now = pc[a[i] xor high] + pc[b[i] xor low];
		if(last && now != last) return false;
		last = now;
	}
	return true;
}

int main(){
	//File("cf1257f");
	in(n);
	for(int i=1; i<=n; i++){
		int x; in(x);
		a[i] = x >> 15; b[i] = x & mask;
	}
	//for(int i=1; i<=n; i++) printf("%d %d\n", a[i], b[i]);
	static int tp[N];
	pc[0] = 0;
	for(int i=1; i<=mask; i++) pc[i] = pc[i>>1] + (i & 1);
	for(int i=0; i<=mask; i++){
		int now = 1;
		for(int j=1; j<=n; j++){
			tp[j] = pc[a[j] xor i];
			now = (1LL * now * (tp[j] + 1) % mod * P % mod + add) % mod;
		}
		//if(i == 0) printf("now = %d\n", now);
		val[now].push_back(i);
	}
	for(int i=0; i<=mask; i++){
		int mxt = 0;
		for(int j=1; j<=n; j++) tp[j] = pc[b[j] xor i], mxt = max(mxt, tp[j]);
		//bool flag = true;
		//for(int j=1; j<=n; j++)
		//	if(tp[j] != mxt) flag = false;
		//if(flag) printf("%d correct.\n", i);
		for(int j=mxt; j<=30; j++){
			int now = 1;
			for(int k=1; k<=n; k++){
				//if(i == 5 && j == mxt) printf("%d ", j - tp[k] + 1);
				now = (1LL * now * (j - tp[k] + 1) % mod * P % mod + add) % mod;
			}
			//if(i == 5 && j == mxt) putchar('\n');
			//if(i == 5 && j == mxt) printf("now = %d\n", now);
			//if(now == 4211416) puts("Correct.");
			for(unsigned p=0; p<val[now].size(); p++)
				if(check(val[now][p], i)){
					printf("%d\n", (val[now][p] << 15) | i);
					return 0;
				}
		}
	}
	puts("-1");
	return 0;
}