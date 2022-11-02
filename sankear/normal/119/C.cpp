#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <double> tc;

const ll inf = (ll)1e18;
const int maxr = 100;

struct tp{
	ll a, b;
	int c, num;
};

int lsta[60];
ll lstb[60];
tp p[60];
ll d[60][60][110];
int pj[60][60][110], pz[60][60][110];

bool operator < (const tp &a, const tp &b){
	return a.c < b.c;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < m; i++){
		scanf("%I64d %I64d %d", &p[i].a, &p[i].b, &p[i].c);
		p[i].num = i;
	}
	sort(p, p + m);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < m; j++){
			for(int z = 0; z <= maxr; z++){
				d[i][j][z] = -inf;
			}
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j <= maxr; j++){
			if(p[i].a + j > p[i].b){
				break;
			}
			d[1][i][j] = p[i].a + j;
		}
	}
	for(int i = 1; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int z = 0; z <= maxr; z++){
				if(d[i][j][z] == -inf){
					continue;
				}
				ll cur = p[j].a + z + k;
				for(int h = j + 1; h < m; h++){
					if(p[h].c > p[j].c){
						if(cur >= p[h].a && cur <= p[h].b){
							ll res = d[i][j][z] + cur;
							if(res > d[i + 1][h][cur - p[h].a]){
								d[i + 1][h][cur - p[h].a] = res;
								pj[i + 1][h][cur - p[h].a] = j;
								pz[i + 1][h][cur - p[h].a] = z;
							}
						}
					}
				}
				cur = (p[j].a + z) * k;
				for(int h = j + 1; h < m; h++){
					if(p[h].c > p[j].c){
						if(cur >= p[h].a && cur <= p[h].b){
							ll res = d[i][j][z] + cur;
							if(res > d[i + 1][h][cur - p[h].a]){
								d[i + 1][h][cur - p[h].a] = res;
								pj[i + 1][h][cur - p[h].a] = j;
								pz[i + 1][h][cur - p[h].a] = z;
							}
						}
					}
				}
			}
		}
	}
	ll ans = -inf;
	int jj, zz;
	for(int i = 0; i < m; i++){
		for(int j = 0; j <= maxr; j++){
			if(d[n][i][j] > ans){
				ans = d[n][i][j];
				jj = i;
				zz = j;
			}
		}
	}
	if(ans == -inf){
		printf("NO\n");
		return 0;
	}
	int sz = 0;
	int i = n;
	int j = jj;
	int z = zz;
	while(i > 0){
		lsta[sz] = p[j].num + 1;
		lstb[sz++] = p[j].a + z;
		jj = pj[i][j][z];
		zz = pz[i][j][z];
		i--;
		j = jj;
		z = zz;
	}
	printf("YES\n");
	for(int i = sz - 1; i >= 0; i--){
		printf("%d %I64d\n", lsta[i], lstb[i]);
	}
	return 0;
}