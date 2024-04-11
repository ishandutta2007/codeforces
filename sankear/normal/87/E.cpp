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

struct tp{
	ll x, y;
	int t;
};

tp q;
tp p[150100], v[150100];

inline ll vec(const tp &a, const tp &b){
	return a.x * b.y - b.x * a.y;
}

bool operator < (const tp &a, const tp &b){
	if(a.t != b.t){
		return a.t < b.t;
	}
	return vec(a, b) > 0;
}

bool operator == (const tp &a, const tp &b){
	return a.t == b.t && vec(a, b) == 0;
}

inline int gett(const tp &a){
	if(a.x > 0 || (a.x == 0 && a.y > 0)){
		return 0;
	}
	return 1;
}

inline bool better(const tp &a, const tp &b){
	if(a.x != b.x){
		return a.x < b.x;
	}
	return a.y < b.y;
}

inline bool check(const tp &a, const tp &b, const tp &c){
	ll s = abs(vec(a, b));
	ll cur = abs(vec(a, c)) + abs(vec(b, c)) + abs((c.x - b.x) * (a.y - b.y) - (a.x - b.x) * (c.y - b.y));
	return s == cur;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int sz = 0;
	ll fx = 0, fy = 0;
	for(int i = 0; i < 3; i++){
		int n;
		scanf("%d", &n);
		for(int j = 0; j < n; j++){
			scanf("%I64d %I64d", &p[j].x, &p[j].y);
		}
		int best = 0;
		for(int j = 1; j < n; j++){
			if(better(p[j], p[best])){
				best = j;
			}
		}
		fx += p[best].x;
		fy += p[best].y;
		p[n] = p[0];
		for(int j = 0; j < n; j++){
			v[sz].x = p[j + 1].x - p[j].x;
			v[sz++].y = p[j + 1].y - p[j].y;
		}
	}
	for(int i = 0; i < sz; i++){
		v[i].t = gett(v[i]);
	}
	sort(v, v + sz);
	int k = 0;
	int i = 0;
	while(i < sz){
		if(v[i].x == 0 && v[i].y == 0){
			i++;
			continue;
		}
		ll sx = 0, sy = 0;
		int j = i;
		while(j < sz && v[i] == v[j]){
			sx += v[j].x;
			sy += v[j].y;
			j++;
		}
		v[k].x = sx;
		v[k++].y = sy;
		i = j;
	}
	p[0].x = fx;
	p[0].y = fy;
	for(int i = 0; i < k - 1; i++){
		p[i + 1].x = p[i].x + v[i].x;
		p[i + 1].y = p[i].y + v[i].y;
	}
	for(int i = 1; i < k; i++){
		p[i].x -= p[0].x;
		p[i].y -= p[0].y;
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%I64d %I64d", &q.x, &q.y);
		q.x *= 3;
		q.y *= 3;
		bool fl = false;
		if(q.x >= p[0].x){
			q.x -= p[0].x;
			q.y -= p[0].y;
			int res = upper_bound(p + 1, p + k, q) - p;
			fl = check(p[1], p[2], q) || check(p[k - 2], p[k - 1], q) || (res != 1 && res != k && check(p[res - 1], p[res], q));
		}
		if(fl){
			printf("YES\n");
			continue;
		}
		printf("NO\n");
	}
	return 0;
}