#include <cstdio>
using namespace std;
const int N = 4e5 + 1;

int n, x, y, cnt[N], cntcnt[N], p, q;

int main(){
	scanf("%d%d", &n, &x);
	cntcnt[0] = x;
	for(int i = 1; i <= n; i++){
		scanf("%d", &y); y %= x;
		cntcnt[cnt[y]]--;
		cnt[y]++;
		cntcnt[cnt[y]]++;
		if(!cntcnt[p]) ++p, q = 0;
		while(cnt[q] > p) q++;
		printf("%d\n", p * x + q);
	}
	return 0;
}