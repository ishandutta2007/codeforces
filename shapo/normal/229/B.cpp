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

using namespace std;

#define maxn 100500
#define maxm 100500
#define INF 2000000000
#define maxk 131072

struct edge{int x, tm;};
struct list{int x, id;};

int n, m;
list tree[2 * maxk];
vector < edge > sm[maxn];
vector < int > ass[maxn];
bool used[maxn];
int dist[maxn];

edge ctr(int a, int b){
	edge res;
	res.x = a;
	res.tm = b;
	return res;
}

bool cmp(const list &a, const list &b){
	return(a.x < b.x || a.x == b.x && a.id <= b.id);
}

list min_list(list &a, list &b){
	if(cmp(a, b))
		return a;
	return b;
}

int init(int n, int k){
	for(int i = k; i < n + k; ++i){
		tree[i].x = INF;
		tree[i].id = i - k + 1;
	}
	for(int i = n + k; i < k * 2; ++i)
		tree[i].x = tree[i].id = INF;
	for(int i = k - 1; i > 0; --i)
		tree[i] = min_list(tree[i * 2], tree[i * 2 + 1]);
	return 0;
}

int upd(int id, int x, int k){
	tree[id + k - 1].x = x;
	tree[id + k - 1].id = id;
	int par = (id + k - 1) / 2;
	while(par){
		tree[par] = min_list(tree[par * 2], tree[par * 2 + 1]);
		par /= 2;
	}
	return 0;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		sm[a].push_back(ctr(b, c));
		sm[b].push_back(ctr(a, c));
	}
	for(int i = 1; i <= n; ++i){
		int ki;
		scanf("%d", &ki);
		for(int it = 1; it <= ki; ++it){
			int ct;
			scanf("%d", &ct);
			ass[i].push_back(ct);
		}
	}
	int mk = 2;
	while(mk < n)mk *= 2;
	init(n, mk);
	memset(used, 0, sizeof(used));
	for(int i = 1; i <= n; ++i){
		dist[i] = INF;
	}
	upd(1, 0, mk);
	while(tree[1].x != INF){
		int xx = tree[1].x, idd = tree[1].id;
		//printf("curi = %d, curtime = %d\n", idd, xx);
		used[idd] = true;
		upd(idd, INF, mk);
		int avail_time;
		int i = 0;
		while(i < ass[idd].size() && ass[idd][i] < xx)++i;
		avail_time = xx;
		while(i < ass[idd].size() && ass[idd][i] == avail_time)
			avail_time = ass[idd][i++] + 1;
		for(int i = 0; i < sm[idd].size(); ++i){
			int to_go = sm[idd][i].x;
			if(dist[to_go] > avail_time + sm[idd][i].tm){
				dist[to_go] = avail_time + sm[idd][i].tm;
				upd(to_go, dist[to_go], mk);
			}
		}
	}
	if(!used[n]){
		printf("-1\n");
	}
	else
		printf("%d\n", dist[n]);
	return 0;
}