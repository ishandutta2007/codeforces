#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

const int inf = (int)2e9;

struct tr{
	int lg, rg;
};

struct trsq{
	int l, r, val;
};

struct tp{
	int l, r, t, num;
};

int cur, cnt, ans, best;
int ver[100100];
tp p[100100];
tp lst[5200100];
trsq rsq[5200100];
tr rmq[280280];

bool operator < (const tp &a, const tp &b){
	return a.l < b.l;
}

inline bool cmp(const tp &a, const tp &b){
	return a.t < b.t;
}

void dfs1(int v, int l, int r){
	if(rsq[v].l > r || rsq[v].r < l){
		return;
	}
	if(rsq[v].l >= l && rsq[v].r <= r){
		ver[cnt++] = v;
		return;
	}
	dfs1(v * 2, l, r);
	dfs1(v * 2 + 1, l, r);
}

void dfs2(int v, int val){
	if(v >= cur){
		if(lst[v - cur + 1].t < ans){
			ans = lst[v - cur + 1].t;
			best = lst[v - cur + 1].num;
		}
		return;
	}
	if(rsq[v * 2].val >= val){
		dfs2(v * 2, val);
		return;
	}
	dfs2(v * 2 + 1, val);
}

int main(){
	//freopen("palindromes.in", "r", stdin);
	//freopen("palindromes.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//cout << (sizeof(p) + sizeof(lst) + sizeof(rsq) + sizeof(rmq)) / 1024 / 1024 << endl;
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &p[i].l, &p[i].r, &p[i].t);
		p[i].num = i;
	}
	sort(p, p + n);
	int maxv = 1;
	while(maxv < n){
		maxv *= 2;
	}
	int sz = 0;
	for(int i = 0; i < n; i++){
		lst[++sz] = p[i];
		rmq[i + maxv].lg = rmq[i + maxv].rg = sz;
	}
	for(int i = maxv - 1; i > 0; i--){
		int oldsz = sz, j = rmq[i * 2].lg, z = rmq[i * 2 + 1].lg;
		while(j > 0 && j <= rmq[i * 2].rg && z > 0 && z <= rmq[i * 2 + 1].rg){
			if(cmp(lst[j], lst[z])){
				lst[++sz] = lst[j++];
			}
			else{
				lst[++sz] = lst[z++];
			}
		}
		while(j > 0 && j <= rmq[i * 2].rg){
			lst[++sz] = lst[j++];
		}
		while(z > 0 && z <= rmq[i * 2 + 1].rg){
			lst[++sz] = lst[z++];
		}
		if(sz > oldsz){
			rmq[i].lg = oldsz + 1;
			rmq[i].rg = sz;
		}
	}
	cur = 1;
	while(cur < sz){
		cur *= 2;
	}
	for(int i = 0; i < cur; i++){
		rsq[i + cur].l = rsq[i + cur].r = i + 1;
	}
	for(int i = cur - 1; i > 0; i--){
		rsq[i].l = rsq[i * 2].l;
		rsq[i].r = rsq[i * 2 + 1].r;
	}
	for(int i = 0; i < sz; i++){
		rsq[i + cur].val = lst[i + 1].r;
	}
	for(int i = sz; i < cur; i++){
		rsq[i + cur].val = -inf;
	}
	for(int i = cur - 1; i > 0; i--){
		rsq[i].val = max(rsq[i * 2].val, rsq[i * 2 + 1].val);
	}
	for(int i = 0; i < m; i++){
		int ql, qr, qt;
		scanf("%d %d %d", &ql, &qr, &qt);
		int res = -1, l = 0, r = n - 1;
		while(l <= r){
			int mid = (l + r) / 2;
			if(p[mid].l <= ql){
				res = mid;
				l = mid + 1;
			}
			else{
				r = mid - 1;
			}
		}
		ans = inf;
		best = -2;
		if(res != -1){
			l = maxv;
			r = res + maxv;
			while(l <= r){
				if(l % 2 != 0 && rmq[l].lg > 0){
					int look = -1, lft = rmq[l].lg, rgh = rmq[l].rg;
					while(lft <= rgh){
						int mid = (lft + rgh) / 2;
						if(lst[mid].t >= qt){
							look = mid;
							rgh = mid - 1;
						}
						else{
							lft = mid + 1;
						}
					}
					if(look != -1){
						cnt = 0;
						dfs1(1, look, rmq[l].rg);
						for(int j = 0; j < cnt; j++){
							if(rsq[ver[j]].val >= qr){
								dfs2(ver[j], qr);
								break;
							}
						}
					}
				}
				l = (l + 1) / 2;
				if(r % 2 == 0 && rmq[r].lg > 0){
					int look = -1, lft = rmq[r].lg, rgh = rmq[r].rg;
					while(lft <= rgh){
						int mid = (lft + rgh) / 2;
						if(lst[mid].t >= qt){
							look = mid;
							rgh = mid - 1;
						}
						else{
							lft = mid + 1;
						}
					}
					if(look != -1){
						cnt = 0;
						dfs1(1, look, rmq[r].rg);
						for(int j = 0; j < cnt; j++){
							if(rsq[ver[j]].val >= qr){
								dfs2(ver[j], qr);
								break;
							}
						}
					}
				}
				r = (r - 1) / 2;
			}
		}
		if(i > 0){
			printf(" ");
		}
		printf("%d", best + 1);
	}
	printf("\n");
	return 0;
}