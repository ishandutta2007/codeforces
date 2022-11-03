/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 140F
 */
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 2E5 + 10, MAXK = 12;

struct VEC{
	long long x, y;

	int read(){
		int tx, ty;
		scanf("%d%d", &tx, &ty);
		x = tx << 1;
		y = ty << 1;
	}

	bool operator<(const VEC& r)const{
		return x != r.x ? x < r.x : y < r.y;
	}

	bool operator==(const VEC& r)const{
		return x == r.x && y == r.y;
	}

	void out(){
		printf("(%d, %d)\n", int(x), int(y));
	}
};

int n, k;
VEC c[MAXN];

vector<VEC> psb;

int check(VEC ct){
	int ret = 0;
	int l = 0, r = n - 1;
	VEC temp;

	while (l <= r){
		temp.x = (ct.x << 1) - c[l].x;
		temp.y = (ct.y << 1) - c[l].y;
		if (temp == c[r]){
			++l;
			--r;
		}
		else{
			++ret;
			if (temp < c[r])
				--r;
			else
				++l;
		}
	}

	return ret;
}

int main(){
	scanf("%d%d", &n, &k);
	for (int i=0;i<n;++i)
		c[i].read();
	sort(c, c + n);

	if (k >= n){
		puts("-1");
		return 0;
	}

	VEC temp;
	for (int i=0;i<=k;++i)
		for (int j=n-k+i-1;j<n;++j){
			temp.x = (c[i].x + c[j].x) >> 1;
			temp.y = (c[i].y + c[j].y) >> 1;
			if (k >= check(temp))
				psb.push_back(temp);
		}

	sort(psb.begin(), psb.end());
	psb.erase(unique(psb.begin(), psb.end()), psb.end());

	printf("%d\n", psb.size());
	for (int i=0;i<psb.size();++i)
		printf("%.1lf %.1lf\n", psb[i].x / 2.0, psb[i].y / 2.0);

	return 0;
}