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

#define maxn 260000
#define maxk 262144

using namespace std;

struct ship{int mass, id, rid;};
struct mrt{long long dist; int mass, id;};

int n, curk;
int pp[maxn];
long long rr[maxn], curd[maxn];
ship tree[2 * maxk];
const long long INF = 2E9;
int q[maxn];
int beg = 1, en = 0;
int power;
long long dist;
mrt sm[maxn];

bool cmp(const mrt &a, const mrt &b){return(a.dist < b.dist || a.dist == b.dist && a.id < b.id);}

int proc(const ship &a, const ship &b, ship &res);

int init(const int &n, const int &shift){
	for(int i = shift; i < shift + n; ++i){
		tree[i].id = sm[i- shift + 1].id;
		tree[i].mass = sm[i - shift + 1].mass;
		tree[i].rid = i - shift + 1;
	}
	for(int i = shift + n; i < 2 * shift; ++i){
		tree[i].id = tree[i].rid;
		tree[i].mass = INF;
	}
	for(int i = shift - 1; i > 0; --i)proc(tree[i * 2], tree[i * 2 + 1], tree[i]);
	return 0;
}

int proc(const ship &a, const ship &b, ship &res){
	if(a.mass <= b.mass)
		res = a;
	else 
		res = b;
	return 0;
}

int update(const int &pos, const int &shift, const int &val){
	tree[pos + shift - 1].mass = val;
	int par = (pos + shift - 1) / 2;
	while(par){
		proc(tree[par * 2], tree[par * 2 + 1], tree[par]);
		par /= 2;
	}
	return 0;
}

ship min_seg(const int &ll, const int &rr, const int &shift){
	int l = ll + shift - 1, r = rr + shift - 1;
	ship res;
	res.id = 0;
	res.mass = INF;
	while(l < r){
		if(l % 2 == 1){
			if(res.mass > tree[l].mass)res = tree[l];
		}
		if(r % 2 == 0){
			if(res.mass > tree[r].mass)res = tree[r];
		}
		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}
	if(l == r){
		if(res.mass > tree[l].mass)res = tree[l];
	}
	return res;
}

int obr(const long long &cur_r, const int &cur_m){
	//long long cur_r = rr[x_id];
	//int cur_m = mm[x_id];
	int ll = 0, rr = n + 1, mm;
	while(ll < rr - 1){
		mm = (ll + rr) / 2;
		if(curd[mm] <= cur_r)
			ll = mm;
		else
			rr = mm;
	}
	int zl = 1, zr = ll;
	//printf("zl = %d, zr = %d, pr = %lld, peak = %lld\n", zl, zr, curd[zr], cur_r);
	ship curs = min_seg(zl, zr, curk);
	//printf("mass = %d, peak = %d, id = %d\n", curs.mass, cur_m, curs.id);
	while(curs.mass <= cur_m){
		//printf("mass = %d, peak = %d, id = %d\n", curs.mass, cur_m, curs.id);
		q[++en] = curs.id;
		update(curs.rid, curk, INF);
		curs = min_seg(zl, zr, curk);
	}
}

int main(){
	int x, y, r;
	scanf("%d%d%d%d%d", &x, &y, &power, &r, &n);
	dist = r; dist = dist * dist;
	curk = 2;
	while(curk < n)curk *= 2;
	for(int i = 1; i <= n; ++i){
		int xx, yy, m, rr1;
		scanf("%d%d%d%d%d", &xx, &yy, &m, &pp[i], &rr1);
		sm[i].id = i;
		sm[i].mass = m;
		long long dx = (x - xx), dy = (y - yy);
		sm[i].dist = dx * dx + dy * dy;
		rr[i] = rr1;
		rr[i] = rr[i] * rr[i];
	}
	sort(sm + 1, sm + n + 1, cmp);
	for(int i = 1; i <= n; ++i)
		curd[i] = sm[i].dist;
	init(n, curk);
	obr(dist, power);
	while(beg <= en){
		//printf("beg = %d\n", beg);
		obr(rr[q[beg]], pp[q[beg]]);
		++beg;
	}
	printf("%d\n", en);
	return 0;
}