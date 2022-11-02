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

typedef long long ll;

const ll inf = (ll)1e15;

struct tp{
	int s, t, c, num;
};

struct tr{
	ll val;
	int pos;
};

int maxv;
bool used[3000];
int p[3000], need[3000];
tp pp[3000];
ll d[3000], pd[3000];
tr rmq[8200];
int c[3000][3000], f[3000][3000], w[3000][3000];

bool operator < (const tp &a, const tp &b){
	return a.s < b.s;
}

bool operator < (const tr &a, const tr &b){
	return a.val < b.val;
}

inline void update(int a, ll b){
	a += maxv;
	rmq[a].val = b;
	while(a > 1){
		a /= 2;
		rmq[a] = min(rmq[a * 2], rmq[a * 2 + 1]);
	}
}

int main(){
	//freopen("b.in", "r", stdin);
	//freopen("b.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//cout << (sizeof(c) + sizeof(f) + sizeof(w)) / 1024 / 1024 << endl;
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &pp[i].s, &pp[i].t, &pp[i].c);
		pp[i].num = i;
	}
	sort(pp, pp + n);
	int s = n + n, t = s + 1;
	for(int i = 0; i < n; i++){
		c[s][i] = 1;
		c[i + n][t] = 1;
		c[i][i + n] = 1;
		w[i][i + n] = -pp[i].c;
		w[i + n][i] = pp[i].c;
	}
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(pp[i].s + pp[i].t - 1 < pp[j].s){
				c[i + n][j] = 1;
			}
		}
	}
	for(int i = 0; i < n; i++){
		pd[i + n] = min(pd[i + n], pd[i] - pp[i].c);
		for(int j = 0; j <= t; j++){
			if(c[i + n][j] > 0){
				pd[j] = min(pd[j], pd[i + n]);
			}
		}
	}
	ll ans = 0;
	maxv = 1;
	while(maxv < t + 1){
		maxv *= 2;
	}
	for(int j = 0; j < maxv; j++){
		rmq[j + maxv].pos = j;
	}
	for(int i = 0; i < k; i++){
		for(int j = 0; j < maxv; j++){
			rmq[j + maxv].val = inf;
		}
		for(int j = maxv - 1; j > 0; j--){
			rmq[j] = min(rmq[j * 2], rmq[j * 2 + 1]);
		}
		for(int j = 0; j <= t; j++){
			d[j] = inf;
			used[j] = false;
		}
		d[s] = 0;
		update(s, d[s]);
		for(int j = 0; j <= t; j++){
			tr cur = rmq[1];
			if(cur.val == inf){
				break;
			}
			used[cur.pos] = true;
			update(cur.pos, inf);
			for(int j = 0; j <= t; j++){
				if(c[cur.pos][j] - f[cur.pos][j] > 0 && d[cur.pos] + pd[cur.pos] + w[cur.pos][j] - pd[j] < d[j]){
					d[j] = d[cur.pos] + pd[cur.pos] + w[cur.pos][j] - pd[j];
					p[j] = cur.pos;
					if(!used[j]){
						update(j, d[j]);
					}
				}
			}
		}
		if(d[t] == inf){
			break;
		}
		for(int j = 0; j <= t; j++){
			pd[j] = min(pd[j] + d[j], inf);
		}
		int j = t;
		while(j != s){
			f[p[j]][j]++;
			f[j][p[j]]--;
			j = p[j];
		}
		ll res = 0;
		for(int j = 0; j < n; j++){
			if(f[j][j + n] > 0){
				res += pp[j].c;
			}
		}
		if(res > ans){
			ans = res;
			for(int j = 0; j < n; j++){
				if(f[j][j + n] > 0){
					need[pp[j].num] = 1;
				}
				else{
					need[pp[j].num] = 0;
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(i > 0){
			printf(" ");
		}
		printf("%d", need[i]);
	}
	printf("\n");
	return 0;
}