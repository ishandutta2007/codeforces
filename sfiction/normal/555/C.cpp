#include <cstdio>
#include <map>
#include <utility>

using namespace std;

typedef pair<int, int> PII;
const int MAXN = 2E5 + 100;
const int INF = 0x3fffffff;

int n, m;
int a[MAXN];
char dire[MAXN][4];
int lenu[MAXN], lenl[MAXN];

void init(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
		scanf("%d%*d%s", &a[i], dire[i]);
}

int main(){
	init();

	map<PII, int> lst;
	lst[make_pair(1, n + 1)] = 0;
	lenu[0] = lenl[0] = 0;
	for (int i = 1; i <= m; ++i){
		map<PII, int>::iterator p = --lst.lower_bound(make_pair(a[i], INF));
		int left = p->first.first, right = p->first.second;
		int id = p->second;
		if (right == a[i]){
			puts("0");
			continue;
		}
		lst.erase(p);

//		printf("(%d, %d), lenu = %d, lenl = %d\n", left, right, lenu[id], lenl[id]);
		if (dire[i][0] == 'U'){
			printf("%d\n", lenu[id] + right - a[i]);
			lenu[i] = lenu[id];
			lenl[i] = 0;
			lenu[id] += right - a[i];
			lst[make_pair(left, a[i])] = id;
			lst[make_pair(a[i] + 1, right)] = i;
		}
		else{
			printf("%d\n", lenl[id] + a[i] - left + 1);
			lenl[i] = lenl[id];
			lenu[i] = 0;
			lenl[id] += a[i] - left + 1;
			lst[make_pair(left, a[i])] = i;
			lst[make_pair(a[i] + 1, right)] = id;
		}
	}

	return 0;
}