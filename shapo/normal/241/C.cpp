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

#define maxn 501

using namespace std;

struct seg{
	int l, r;
	int res, id;
};

int hl, hr;
int n;
seg sm[maxn][maxn];
int num[maxn];
const int len = 100000, h = 100;
int res = 0;
int used[maxn];

int get_h(int hh, int lvl){
	if(!lvl)return(hh - h);
	if(lvl & 1)return lvl * h - hh;
	return h * (lvl - 1) + hh;
}

bool isect(int x1, int x2, int y1, int yu, int yd){
	int h1 = y1 - yu, h2 = yd - yu;
	return ((long long)(h1) * (long long)(len) >= (long long)(h2) * (long long)(x1) && 
	(long long)(h1) * (long long)(len) <= (long long)(h2) * (long long)(x2));
}

int go(int beg, int en, int lvl){
	memset(used, 0, sizeof(used));
	if(beg > en)return 0;
	int cres = 0;
	for(int i = 0; i < lvl; ++i){
		int now = 0;
		for(int j = 0; j < num[i]; ++j)
			if(h * i > beg && isect(sm[i][j].l, sm[i][j].r, h * i, beg, en)){
				if(used[sm[i][j].id])return 0;
				++now;
				used[sm[i][j].id] = 1;
				cres += sm[i][j].res;
			}
		if(h * i > beg && !now)return 0;
	}
	res = max(res, cres);
	return 0;
}

int main(){
	cin >> hl >> hr >> n;
	num[0] = num[1] = 0;
	for(int i = 1; i <= n; ++i){
		char c;
		int v, a, b;
		cin >> v >> skipws >> c >> a >> b;
		assert(c == 'T' || c == 'F');
		if(c == 'T'){
			sm[0][num[0]].l = a;
			sm[0][num[0]].r = b;
			sm[0][num[0]].res = v;
			sm[0][num[0]].id = i;
			num[0]++;
		}
		else{
			sm[1][num[1]].l = a;
			sm[1][num[1]].r = b;
			sm[1][num[1]].res = v;
			sm[1][num[1]].id = i;
			num[1]++;
		}
	}
	for(int i = 2; i <= max(2 * n, n + 10); ++i){
		num[i] = num[i - 2];
		for(int j = 0; j < num[i]; ++j){
			sm[i][j].l = sm[i - 2][j].l;
			sm[i][j].r = sm[i - 2][j].r;
			sm[i][j].res = sm[i - 2][j].res;
			sm[i][j].id = sm[i - 2][j].id;
		}
	}
	for(int i = 0; i <= n + 2; ++i){
		int nk = get_h(hr, i);
		go(hl - h, nk, i);
		go(h - hl, nk, i);
	}
	cout << res << endl;
	return 0;
}