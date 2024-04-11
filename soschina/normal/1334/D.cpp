#include <cstdio>
using namespace std;

int t, n, id;
long long s, l, r, lim;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%lld%lld", &n, &l, &r);
		lim = 1ll * n * (n - 1) + 1;
		s = 0, id = 1;
		for(long long i = l; i <= r && i < lim; i++){
			while(s + (n - id) * 2 < i) s += (n - id) << 1, id++;
			int d = i - s;
			printf("%d ", (d & 1) ? id : d / 2 + id);
		}
		if(r == lim) printf("1 ");
		putchar('\n');
	}
	return 0;
}