#include <stdio.h>
#include <queue>
#include <map>
using namespace std;
const int maxn = 200010;
typedef pair<int, int> Pair;
struct Edge{
	int u, v, nxt;
}e[2 * maxn];
int head[maxn], x[maxn], y[maxn], d[maxn], e_cnt, ans[maxn];
queue<int> q;
map<Pair, bool> mmap;
void Add(int u, int v){
	int id = e_cnt++;
	e[id].u = u;
	e[id].v = v;
	e[id].nxt = head[u];
	head[u] = id;
}
int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++)
		head[i] = -1;
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &x[i], &y[i]);
		d[x[i]]++;
		d[y[i]]++;
		Add(x[i], y[i]);
		Add(y[i], x[i]);
	}
	int cnt = n;
	for(int i = 1; i <= n; i++)
		if(d[i] < k){
			cnt--;
			q.push(i);
		}
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int id = head[u]; id != -1; id = e[id].nxt){
			int v = e[id].v;
			if(d[v] >= k && --d[v] < k){
				q.push(v);
				cnt--;
			}
		}
	}
	ans[m] = cnt;
	for(int i = m; i > 0; i--){
		if(d[x[i]] < k || d[y[i]] < k){
			ans[i-1] = cnt;
			continue;
		}
		if(--d[x[i]] < k) q.push(x[i]), cnt--;
		if(--d[y[i]] < k) q.push(y[i]), cnt--;
		mmap[Pair(x[i], y[i])] = true;
		mmap[Pair(y[i], x[i])] = true;
		while(!q.empty()){
			int u = q.front(); q.pop();
//			printf("i:%d u:%d\n", i, u);
			for(int id = head[u]; id != -1; id = e[id].nxt){
				int v = e[id].v;
				if(mmap[Pair(u, e[id].v)]) continue;
				if(d[v] >= k && --d[v] < k){
					q.push(v);
					cnt--;
				}
//				printf("u:%d v:%d dv:%d\n", u, v, d[v]);
			}
		}
		ans[i-1] = cnt;
//		printf("i:%d cnt:%d\n", i, cnt);
	}
	for(int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
	return 0;
}