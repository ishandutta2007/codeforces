#include <cstdio>
#include <algorithm>
#include <vector>
#define lowbit(i) (i&-i)
using namespace std;
const int N = 2e5 + 1, M = 1e6 + 2, K = 3e5 + 1; 

int t, n, m, k, rx[N], ry[N], x, y, lenx, leny, cnt;
struct p_x{
	int x, y;
	bool operator<(const p_x &b) const{
		return x < b.x;
	}
}px[K];
struct p_y{
	int x, y;
	bool operator<(const p_y &b) const{
		return y < b.y;
	}
}py[K];
bool hx[M], hy[M];
long long ans;

int tree[M];
void add(int i, int x){
	while(i < M){
		tree[i] += x;
		i += lowbit(i);
	}
}

int sum(int i){
	int ret = 0;
	while(i){
		ret += tree[i];
		i -= lowbit(i);
	}
	return ret;
}

vector<int> vec[M]; 

int main(){
	scanf("%d", &t);
	while(t--){
		cnt = 0;
		lenx = leny = 0;
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 1; i <= n; i++)
			scanf("%d", rx + i), hx[++rx[i]] = true;
		for(int i = 1; i <= m; i++)
			scanf("%d", ry + i), hy[++ry[i]] = true;
		for(int i = 1; i <= k; i++){
			scanf("%d%d", &x, &y);
			x++, y++;
			if(hx[x] && hy[y]) cnt++;
			else if(hx[x]) py[++leny] = (p_y){x, y};
			else if(hy[y]) px[++lenx] = (p_x){x, y};
		}
		ans = 1ll * cnt * (lenx + leny) + 1ll * cnt * (cnt - 1) / 2 + 1ll * lenx * leny;
		x = 1, y = 1;
		sort(px + 1, px + 1 + lenx);
		sort(py + 1, py + 1 + leny);
		for(int i = 1; i <= lenx; i++){
			while(x < n && rx[x + 1] < px[i].x) x++;
			int id = lower_bound(vec[px[i].y].begin(), vec[px[i].y].end(), rx[x]) - vec[px[i].y].begin();
			ans += vec[px[i].y].size() - id;
			vec[px[i].y].push_back(px[i].x);
			ans += sum(rx[x]);
			add(px[i].x, 1);
		}
		for(int i = 1; i <= lenx; i++)
			add(px[i].x, -1), vec[px[i].y].clear();
		for(int i = 1; i <= leny; i++){
			while(y < m && ry[y + 1] < py[i].y) y++;
			int id = lower_bound(vec[py[i].x].begin(), vec[py[i].x].end(), ry[y]) - vec[py[i].x].begin();
			ans += vec[py[i].x].size() - id;
			vec[py[i].x].push_back(py[i].y);
			ans += sum(ry[y]);
			add(py[i].y, 1);
		}
		for(int i = 1; i <= leny; i++)
			add(py[i].y, -1), vec[py[i].x].clear();
		printf("%lld\n", 1ll * k * (k - 1) / 2 - ans);
		for(int i = 1; i <= n; i++)
			hx[rx[i]] = false;
		for(int i = 1; i <= m; i++)
			hy[ry[i]] = false;
	}
}