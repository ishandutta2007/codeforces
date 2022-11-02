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

const int inf = (int)1e9;

struct tr{
	int val, num;
};

int k, maxv;
tr cur;
bool used[100100];
int d[100100], first[100100];
int go[200200], cnt[200200], next[200200];
tr rmq[280100];

bool operator < (const tr &a, const tr &b){
	return a.val < b.val;
}

inline void add(int a, int b, int c){
	go[++k] = b;
	cnt[k] = c;
	next[k] = first[a];
	first[a] = k;
}

inline void update(int a, int b){
	a += maxv;
	rmq[a].val = b;
	while(a > 1){
		a /= 2;
		rmq[a] = min(rmq[a * 2], rmq[a * 2 + 1]);
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, s;
	scanf("%d %d %d", &n, &m, &s);
	s--;
	k = 0;
	for(int i = 0; i < m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--;
		b--;
		add(a, b, c);
		add(b, a, c);
	}
	int l;
	scanf("%d", &l);
	maxv = 1;
	while(maxv < n){
		maxv *= 2;
	}
	for(int i = 0; i < n; i++){
		d[i] = inf;
	}
	for(int i = 0; i < maxv; i++){
		rmq[i + maxv].val = inf;
		rmq[i + maxv].num = i;
	}
	for(int i = maxv - 1; i > 0; i--){
		rmq[i] = min(rmq[i * 2], rmq[i * 2 + 1]);
	}
	d[s] = 0;
	update(s, d[s]);
	for(int i = 0; i < n; i++){
		cur = rmq[1];
		if(cur.val == inf){
			break;
		}
		used[cur.num] = true;
		update(cur.num, inf);
		for(int j = first[cur.num]; j > 0; j = next[j]){
			if(d[go[j]] > d[cur.num] + cnt[j]){
				d[go[j]] = d[cur.num] + cnt[j];
				if(!used[go[j]]){
					update(go[j], d[go[j]]);
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(d[i] == l){
			ans++;
		}
	}
	int res = 0;
	for(int i = 0; i < n; i++){
		if(d[i] < l){
			for(int j = first[i]; j > 0; j = next[j]){
				if(d[i] + cnt[j] > l){
					if(d[go[j]] + cnt[j] - l + d[i] >= l){
						ans++;
						if(d[go[j]] + cnt[j] - l + d[i] == l && i < go[j]){
							res++;
						}
					}
				}
			}
		}
	}
	ans -= res;
	printf("%d\n", ans);
	return 0;
}