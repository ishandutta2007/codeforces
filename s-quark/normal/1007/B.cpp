#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef double R;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

const R PI = acos(-1);
const int MAXN = 1<<20;
const int P = 1e9+7;

ll cnt[8];
ll f[4];
bool vis[MAXN];

vector<int> v;

ll C3(ll n){
	return n * (n+1) * (n+2) / 6;
}

ll C2(ll n){
	return n * (n+1) / 2;
}

namespace MyCode {
int main(){
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int t;

	scanf("%d", &t);
	while(t--){
		int a[3];
		int i, j, k;

		scanf("%d%d%d", &a[0], &a[1], &a[2]);
		for(i = 0; i < 3; i++){
			for(j = 1; j*j <= a[i]; j++)
				if(a[i] % j == 0){
					k = j;
					if(!vis[k]){
						vis[k] = true;
						v.pb(k);
						int x = 0;
						for(int y = 0; y < 3; y++)
							if(a[y] % k == 0)
								x ^= 1<<y;
						cnt[x]++;
					}
					k = a[i] / j;
					if(!vis[k]){
						vis[k] = true;
						v.pb(k);
						int x = 0;
						for(int y = 0; y < 3; y++)
							if(a[y] % k == 0)
								x ^= 1<<y;
						cnt[x]++;
					}
				}
		}

		ll ans = 0;
		ans += C3(cnt[7]);
		ans += C2(cnt[7]) * accumulate(cnt+1, cnt+7, 0LL);
		ans += C2(cnt[3]) * (cnt[4] + cnt[5] + cnt[6] + cnt[7]);
		ans += C2(cnt[5]) * (cnt[2] + cnt[3] + cnt[6] + cnt[7]);
		ans += C2(cnt[6]) * (cnt[1] + cnt[3] + cnt[5] + cnt[7]);
		f[0] = 1;
		for(i = 1; i < 8; i++){
			for(j = 3; j > 0; j--)
				f[j] += f[j-1] * cnt[i];
		}
		ans += f[3];
		ans -= cnt[1] * cnt[2] * cnt[3];
		ans -= cnt[1] * cnt[4] * cnt[5];
		ans -= cnt[2] * cnt[4] * cnt[6];
		printf("%I64d\n", ans);

		memset(f, 0, sizeof f);
		memset(cnt, 0, sizeof cnt);
		for(int x : v)
			vis[x] = false;
		v.clear();
	}
	return 0;
}
}

int main(){
	return MyCode::main();
}