#include <cstdio>
using namespace std;

int T, n, k, l, d, t, nxt;

int main(){
	scanf("%d", &T);
	while(T--){
		bool flag = true;
		scanf("%d%d%d", &n, &k, &l);
		t = (k + 1) % (2 * k);
		while(n--){
			scanf("%d", &d);
			if(d > l) flag = false;
			else if(d + k <= l) t = k;
			else if(t > 0 && t <= k){
				if(d + t > l) flag = false;
			}else if(t > k){
				nxt = (2ll * k - l + d) % (2 * k);
				if(nxt == 0) t = 0;
				else if(nxt > t) t = nxt;
			}
			++t %= 2 * k;
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}