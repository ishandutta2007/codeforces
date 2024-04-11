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

#define maxn 1005000
#define maxm 10050
#define maxc 256

using namespace std;

struct pos{int x, id;};

int n, m;
char s[maxn];
int rght[maxc];
int nnum;
pos upr[maxm];
int unq[maxm];
int ans[maxm];
char cur_s[maxc];
int go[maxn][20];
int md[maxn];
const int cns = 65536;
int cur[cns], res[cns];

bool cmp(const pos &a, const pos &b){return(a.x < b.x || a.x == b.x && a.id < b.id);}

int proc_data(){
	scanf(" %s", s);
	n = strlen(s);
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i){
		scanf(" %s", cur_s);
		int cur_m = 0;
		for(int ii = 0; ii < strlen(cur_s); ++ii)
			cur_m |= (1 << (cur_s[ii] - 'a'));
		upr[i].x = cur_m;
		upr[i].id = i;
	}
	sort(upr + 1, upr + m + 1, cmp);
	nnum = 0;
	for(int i = 1; i <= m; ++i)
		if(i == m || upr[i].x != upr[i + 1].x)unq[++nnum] = upr[i].x;
	for(int i = 0; i < n; ++i)go[i + 1][0] = (1 << (s[i] - 'a'));
	for(int i = 1; i < 20; ++i)
		for(int j = 0; j < n - (1 << (i - 1)); ++j)
			go[j + 1][i] = go[j + 1][i - 1] | go[j + (1 << (i - 1)) + 1][i - 1];
	md[1] = 0;
	for(int i = 2; i <= n; ++i)md[i] = md[i / 2] + 1;
	return 0;
}

int find_seg(const int &ll, const int &rr){
	int cp = md[rr - ll + 1];
	int res = go[ll][cp] | go[rr - (1 << cp) + 1][cp];
	return res;
}

int make_answers(){
	memset(cur, 0, sizeof(cur));
	for(int i = 1; i <= nnum; ++i){
		int now_pos = unq[i] & (cns - 1);
		while(cur[now_pos])now_pos = (now_pos + 1) & (cns - 1);
		cur[now_pos] = unq[i];
	}
	s[n] = 'z' + 1;
	for(int i = 'a'; i <= 'z'; ++i)rght[i] = n + 20;
	rght['z' + 1] = 0;
	for(int i = 1; i <= n + 1; ++i){
		if(i != 1){
			for(int c = 'a'; c <= 'z' + 1; ++c)
				if(rght[c] < i - 1){
					//printf("rght[%c] = %d\n", c, rght[c]);
					int fnd = find_seg(rght[c] + 1, i - 1), tf = fnd & (cns - 1);
					if((fnd | (1 << (s[i - 1] - 'a'))) != fnd){
						//printf("fnd = %d, tf = %d %d\n", fnd, tf, (1 << (s[i - 1] - 'a')));
						while(cur[tf] != 0 && cur[tf] != fnd)tf = (tf + 1) & (cns - 1);
						if(cur[tf] == fnd)++res[tf];
					}
				}
		}
		if(i != n + 1)rght[s[i - 1]] = i;
	}
	for(int i = 1; i <= m; ++i){
		int pk = upr[i].x & (cns - 1);
		//printf("pk = %d %d\n", pk, upr[i].x);
		while(cur[pk] != 0 && cur[pk] != upr[i].x)pk = (pk + 1) & (cns - 1);
		ans[upr[i].id] = res[pk];
	}
	for(int i = 1; i <= m; ++i)
		printf("%d\n", ans[i]);
	return 0;
}

int main(){
	proc_data();
	make_answers();

	return 0;
}