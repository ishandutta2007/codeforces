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

struct tp{
	int x, y, num, t;
};

int ans, num1, num2;
tp p[100100], cp[100100], pp[100100];

bool cmpx(const tp &a, const tp &b){
	return a.x < b.x;
}

bool cmpy(const tp &a, const tp &b){
	return a.y < b.y;
}

inline int sqr(int a){
	return a * a;
}

inline void update(const tp &a, const tp &b){
	int res = sqr(a.x - b.x) + sqr(a.y - b.y);
	if(res < ans){
		ans = res;
		num1 = a.num;
		num2 = b.num;
	}
}

void doit(int l, int r){
	if(r - l < 4){
		for(int i = l; i < r; i++){
			for(int j = i + 1; j <= r; j++){
				update(cp[i], cp[j]);
			}
		}
		sort(cp + l, cp + r + 1, cmpy);
		return;
	}
	int mid = (l + r) / 2;
	int midx = cp[mid].x;
	doit(l, mid);
	doit(mid + 1, r);
	inplace_merge(cp + l, cp + mid + 1, cp + r + 1, cmpy);
	int sz = 0;
	for(int i = l; i <= r; i++){
		if(abs(cp[i].x - midx) < ans){
			for(int j = sz - 1; j >= 0 && cp[i].y - pp[j].y < ans; j--){
				update(cp[i], pp[j]);
			}
			pp[sz++] = cp[i];
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
  int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &p[i].x, &p[i].y);
		if(p[i].x >= 0 && p[i].y >= 0){
			p[i].t = 1;
			continue;
		}
		if(p[i].x >= 0 && p[i].y < 0){
			p[i].t = 2;
			p[i].y = -p[i].y;
			continue;
		}
		if(p[i].x < 0 && p[i].y >= 0){
			p[i].t = 3;
			p[i].x = -p[i].x;
			continue;
		}
		p[i].t = 4;
		p[i].x = -p[i].x;
		p[i].y = -p[i].y;
	}
	for(int i = 0; i < n; i++){
		cp[i] = p[i];
		cp[i].num = i;
	}
	sort(cp, cp + n, cmpx);
	ans = inf;
	doit(0, n - 1);
	if(p[num1].t == 2){
		p[num1].t = 3;
	}
	else{
		if(p[num1].t == 3){
			p[num1].t = 2;
		}
	}
	if(p[num2].t == 1){
		p[num2].t = 4;
	}
	else{
		if(p[num2].t == 4){
			p[num2].t = 1;
		}
	}
	printf("%d %d %d %d\n", num1 + 1, p[num1].t, num2 + 1, p[num2].t);
	return 0;
}