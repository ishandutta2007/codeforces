//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const int N = 3e8+5, W = 3e8, P = 2e7+5;

bitset<N> tab;
int l, r, prime[P], tot, ans;
void getPrime(int x) {
	rep(i, 2, x) tab.set(i);
	rep(i, 2, x) {
		if(tab[i]) prime[tot++] = i;
		for(int j=0;j<tot&&prime[j]*i<=x;j++) {
			tab[prime[j]*i] = 0;
			if(!(i % prime[j])) break;
		}
	}
}

int main() {
	scanf("%d%d", &l, &r);
	getPrime(r);
	rep(i, 0, tot-1) {
		if(prime[i] < l) continue;
		if(prime[i] > r) break;
		ans += prime[i] % 4 == 1;
	}
	ans += l <= 2 && r >= 2;
	printf("%d\n", ans);
	return 0;
}