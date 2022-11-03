#include <cstdio>
#include <map>
#include <set>
#include <utility>

#define mp(x, y) make_pair((x), (y))

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

const int MAXN = 1E5 + 100;
const ll MOD = 1E9 + 9;

int n;
int x[MAXN], y[MAXN];
map<PII, int> lst;
set<int> ava;

int spt[MAXN];

bool movable(int i){
	for (int dx = -1; dx <= 1; ++dx){
		PII t = mp(x[i] + dx, y[i] + 1);
		if (lst.find(t) != lst.end() && spt[lst[t]] == 1)
			return false;
	}
	return true;
}

void countSupport(int i){
	if (y[i] == 0){
		spt[i] = 3;
	}
	else{
		spt[i] = 0;
		for (int dx = -1; dx <= 1; ++dx)
			spt[i] += lst.find(mp(x[i] + dx, y[i] - 1)) != lst.end();
	}
}

int main(){
	scanf("%d", &n);
	lst.clear();
	for (int i = 0; i < n; ++i){
		scanf("%d%d", &x[i], &y[i]);
		lst[mp(x[i], y[i])] = i;
	}
	for (int i = 0; i < n; ++i){
		countSupport(i);
	}

	ava.clear();
	for (int i = 0; i < n; ++i)
		if (movable(i)){
			ava.insert(i);
		}

	ll ans = 0;
	int user = 0;
	while (lst.size()){
//		printf("%d %d\n", lst.size(), ava.size());
		int u;
		u = *(user ? ava.begin() : --ava.end());
		ans = (ans * n + u) % MOD;
		lst.erase(mp(x[u], y[u]));
		ava.erase(u);
		user ^= 1;

		map<PII, int>::iterator p;
		for (int dx = -1; dx <= 1; ++dx){
			PII t = mp(x[u] + dx, y[u] - 1);
			if ((p = lst.find(t)) != lst.end() && movable(p->second)){
				ava.insert(p->second);
			}

			t = mp(x[u] + dx, y[u] + 1);
			if ((p = lst.find(t)) != lst.end()){
				int v = p->second;
				--spt[v];
				for (int ddx = -1; ddx <= 1; ++ddx){
					p = lst.find(mp(x[v] + ddx, y[v] - 1));
					if (p != lst.end() && (!movable(p->second))){
						ava.erase(p->second);
					}
				}
			}
		}
	}
	printf("%d\n", (int)ans);

	return 0;
}