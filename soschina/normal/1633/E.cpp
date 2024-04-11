#include <cstdio>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 51, M = 301;

int n, m, id[M];
struct edge{
	int u, v, w;
}e[M];

int constant;
bool cmp(int a, int b){
	return abs(e[a].w - constant) < abs(e[b].w - constant);
}

set<int> st;
vector<int> pos;
vector< vector<int> > ord;

int fa[N];
int find(int x){
	//printf("finding %d\n", x);
	int ret = (fa[x] == x ? x : fa[x] = find(fa[x]));
	//printf("finded %d\n", ret);
	return ret;
}

int p, k, a, b, c, q;
long long ans;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	st.insert(0);
	for(int i = 2; i <= m; i++)
		for(int j = 1; j < i; j++)
			st.insert((e[i].w + e[j].w) / 2 + 1);
	for(int x : st)
		pos.push_back(x);
	ord.resize(pos.size());
	for(int i = 0; i < ord.size(); i++){
		//printf("calc %d\n", pos[i]);
		for(int j = 1; j <= m; j++)
			id[j] = j;
		constant = pos[i];
		sort(id + 1, id + 1 + m, cmp);
		for(int j = 1; j <= n; j++){
			//printf("fa[%d] = %d\n", j, fa[j]);
			fa[j] = j;
			//printf("fa[%d] = %d\n", j, fa[j]);
		}
		for(int j = 1; j <= m; j++){
			//printf("find edge %d %d\n", e[id[j]].u, e[id[j]].v);
			int x = find(e[id[j]].u), y = find(e[id[j]].v);
			//printf("find %d %d\n", x, y);
			if(x != y){
				ord[i].push_back(id[j]);
				//printf("push %d %d %d\n", e[id[j]].u, e[id[j]].v, e[id[j]].w);
				fa[x] = y;
			}
		}
	}
	scanf("%d%d%d%d%d", &p, &k, &a, &b, &c);
	for(int i = 1; i <= p; i++){
		scanf("%d", &q);
		int x = upper_bound(pos.begin(), pos.end(), q) - pos.begin() - 1;
		long long now = 0;
		for(int j : ord[x])
			now += abs(e[j].w - q);
		//printf("q: %d, ans: %lld\n", q, now);
		ans ^= now;
	}
	for(int i = p + 1; i <= k; i++){
		q = (1ll * q * a + b) % c;
		int x = upper_bound(pos.begin(), pos.end(), q) - pos.begin() - 1;
		long long now = 0;
		for(int j : ord[x])
			now += abs(e[j].w - q);
		//printf("q: %d, ans: %lld\n", q, now);
		ans ^= now;
	}
	printf("%lld", ans);
	return 0;
}