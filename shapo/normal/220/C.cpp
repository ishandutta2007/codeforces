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

using namespace std;

#define maxn 100500
#define maxk 131072

struct event
{
	int time, x, val, id;
};

const int MV = 1000000000;
int n, st2;
int a[maxn], b[maxn];
int ina[maxn], inb[maxn];
int res[maxn];
int increase[2 * maxk], decrease[2 * maxk];
event sm[3 * maxn];
int num_event;

bool cmp(const event &a, const event &b)
{
	return(a.time < b.time);
}

int input(int l, int r, int *arr)
{
	for(int i = l; i <= r; ++i)
		scanf("%d", arr + i);
	return 0;
}

int output(int l, int r, int *arr)
{
	for(int i = l; i <= r; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}

int add_event(const int &time, const int &x, const int &val, const int &id)
{
	//printf("for %x:\n", x);
	//printf("\ttime = %d, val = %d, id = %d\n", time, val, id);
	sm[num_event].time = time;
	sm[num_event].x = x;
	sm[num_event].val = val;
	sm[num_event++].id = id;
	return 0;
}

int init(const int &shift, const int &def, int *tree)
{
	for(int i = 1; i < 2 * shift; ++i)
		tree[i] = def;
	return 0;
}

int change(const int &n, const int &shift, const int &val, int *tree)
{
	tree[n + shift - 1] = val;
	int par = (n + shift - 1) / 2;
	while(par) {
		tree[par] = min(tree[par * 2], tree[par * 2 + 1]);
		par /= 2;
	}
	return 0;
}

int query(const event &cur, const int &delay)
{
	if(cur.id == 1)
	{
		change(cur.x, st2, MV, decrease);
		change(cur.x, st2, cur.val - delay, increase);
		return 0;
	}
	change(cur.x, st2, MV, increase);
	change(cur.x, st2, cur.val + delay, decrease);
	return 0;
}

int process()
{
	num_event = 0;
	st2 = 2;
	while(st2 < n)st2 *= 2;
	init(st2, MV, increase);
	init(st2, MV, decrease);
	for(int i = 1; i <= n; ++i){
		ina[a[i]] = i;
		inb[b[i]] = i;
	}
	for(int i = 1; i <= n; ++i){
		//printf("i = %d inb = %d, ina = %d\n", i, inb[i], ina[i]);
		if(inb[i] < ina[i]){
			add_event(1, i, ina[i] - inb[i], 1);
			if(ina[i] != n)
				add_event(inb[i] + 1, i, n - ina[i], -1);
			add_event(n - ina[i] + inb[i] + 1, i, 0, 1);
			continue;
		}
		if(inb[i] > ina[i]){
			add_event(1, i, inb[i] - ina[i], -1);
			add_event(inb[i] - ina[i] + 1, i, 0, 1);
			if(inb[i] != n)
				add_event(inb[i] + 1, i, n - ina[i], -1);
			continue;
		}
		if(inb[i] == ina[i]){
			add_event(1, i, 0, 1);
			add_event(inb[i] + 1, i, n - ina[i], -1);
			continue;
		}
	}
	sort(sm, sm + num_event, cmp);
	int left_uk = 0;
	for(int i = 1; i <= n; ++i){
		while(left_uk < num_event && sm[left_uk].time == i){
			//printf("left_uk = %d, time = %d\n", left_uk, sm[left_uk].time);
			query(sm[left_uk++], i - 1);
		}
		res[i] = min(increase[1] + i - 1, decrease[1] - i + 1);
	}
	return 0;
}

int main()
{
	while(scanf("%d", &n) == 1){
		input(1, n, a);
		input(1, n, b);
		process();
		output(1, n, res);
	}
	return 0;
}