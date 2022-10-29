#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <set>

#define maxn 10000500
#define maxm 100500

using namespace std;

const int INF = 1E9;
int prime[maxn];
int lp[maxn], num = 0;
int n, m;
int c1[maxn], c2[maxn];
int res[maxm], nres = 0;
int res1[maxm], nres1 = 0;
int a[maxm], b[maxm];

int gen_prime(){
	memset(prime, 0, sizeof(prime));
	prime[0] = prime[1] = INF;
	for(int i = 2; i < maxn; ++i){
		if(prime[i] == 0){
			lp[++num] = i;
			prime[i] = i;
		}
		for(int j = 1; j <= num && lp[j] <= prime[i] && i * lp[j] < maxn; ++j)
			prime[i * lp[j]] = lp[j];
	}
	return 0;
}

int main(){
	gen_prime();
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i){
		int cc;
		scanf("%d", &cc);
		a[i + 1] = cc;
		while(cc != 1){
			++c1[prime[cc]];
			cc /= prime[cc];
		}
	}
	for(int i = 0; i < m; ++i){
		int cc;
		scanf("%d", &cc);
		b[i + 1] = cc;
		while(cc != 1){
			++c2[prime[cc]];
			cc /= prime[cc];
		}
	}
	int rc(0), lc(0);
	for(int i = 2; i < maxn; ++i){
		int pk = min(c1[i], c2[i]);
		c1[i] -= pk;
		c2[i] -= pk;
		lc += c1[i];
		rc += c2[i];
	}
	nres = n;
	nres1 = m;
	for(int i = 1; i <= n; ++i){
		res[i] = 1;
		int cc = a[i];
		while(cc != 1){
			if(c1[prime[cc]]){
				res[i] *= prime[cc];
				--c1[prime[cc]];
			}
			//printf("cc = %d\n", cc);
			cc /= prime[cc];
		}
	}
	for(int i = 1; i <= m; ++i){
		res1[i] = 1;
		int cc = b[i];
		while(cc != 1){
			if(c2[prime[cc]]){
				res1[i] *= prime[cc];
				--c2[prime[cc]];
			}
			cc /= prime[cc];
		}
	}
	printf("%d %d\n", nres, nres1);
	for(int i = 1; i <= nres; ++i)
		printf("%d ", res[i]);
	printf("\n");
	for(int i = 1; i <= nres1; ++i)
		printf("%d ", res1[i]);
	printf("\n");
	return 0;
}