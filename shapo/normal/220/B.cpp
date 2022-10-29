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

#define maxn 100500
#define maxk 131072

using namespace std;

struct pos{int x, id;};

int f[maxn], rk[maxn];
pos a[maxn];
int n, m, kr;
int ll[maxn], res[maxn];
vector< int > rr[maxn];
int tree[2 * maxk];
int lleft[maxn], last[maxn];

bool cmp(const pos &a, const pos &b){return(a.x < b.x || a.x == b.x && a.id < b.id);}

int update(int x, int shift, int val){
	tree[x + shift - 1] = val;
	int par = (x + shift - 1) / 2;
	while(par){
		tree[par] = tree[par * 2] + tree[par * 2 + 1];
		par /= 2;
	}
	return 0;
}

int get_ans(int l, int r, int shift){
	int res = 0, ll = l + shift - 1, rr = r + shift - 1;
	while(ll < rr){
		if(ll % 2 == 1)res += tree[ll];
		if(rr % 2 == 0)res += tree[rr];
		ll = (ll + 1) / 2;
		rr = (rr - 1) / 2;
	}
	if(ll == rr)res += tree[ll];
	return res;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i].x);
		a[i].id = i;
		rk[i] = a[i].x;
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= m; ++i){
		scanf("%d%d", &ll[i], &kr);
		rr[kr].push_back(i);
	}
	for(int i = 1; i <= n; ++i)
		if(i - a[i].x + 1 >= 1 && a[i - a[i].x + 1].x == a[i].x)
			f[a[i].id] = a[i - a[i].x + 1].id;
		else
			f[a[i].id] = n * 100;
	//for(int i = 1; i <= n; ++i)printf("f[%d] = %d\n", i, f[i]);
	int kk = 1;
	while(kk < n)kk *= 2;
	for(int i = 1; i <= n; ++i){
		a[i].x = rk[i];
		if(a[i].x <= n){
			if(lleft[a[i].x]){
				update(lleft[a[i].x], kk, -1);
				if(last[lleft[a[i].x]])
					update(last[lleft[a[i].x]], kk, 0);
			}
			if(f[i] <= n){
				last[f[i]] = lleft[a[i].x];
				lleft[a[i].x] = f[i];
				update(lleft[a[i].x], kk, 1);
			}
			else
				lleft[a[i].x] = 0;
		}
		for(int j = 0; j < rr[i].size(); ++j){
			//printf("%d %d\n", i, ll[rr[i][j]]);
			res[rr[i][j]] = get_ans(ll[rr[i][j]], i, kk);
		}
	}
	for(int i = 1; i <= m; ++i)
		printf("%d\n", res[i]);	

	return 0;
}