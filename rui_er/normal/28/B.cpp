//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const int N = 105;

int n, fa[N], aim[N], dis[N];
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
void merge(int x, int y) {fa[find(x)] = find(y);}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) fa[i] = i;
	rep(i, 1, n) scanf("%d", &aim[i]);
	rep(i, 1, n) {
		scanf("%d", &dis[i]);
		if(i - dis[i] >= 1) merge(i, i-dis[i]);
		if(i + dis[i] <= n) merge(i, i+dis[i]);
	}
	rep(i, 1, n) if(find(i) != find(aim[i])) return puts("NO"), 0;
	puts("YES");
	return 0;
}