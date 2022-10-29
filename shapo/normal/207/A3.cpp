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

#define maxn 200500

using namespace std;

struct list{int x, id, til;};

int n;
list sm[maxn];

bool cmp(const list& a, const list& b){
	return(a.til < b.til || a.til == b.til && a.x < b.x);
}

int main(){
	cin >> n;
	int res (0), curnum (0);
	for(int i = 1; i <= n; ++i){
		long long x, y, m, curt (-1), cp;
		int num, cur_d (0);
		cin >> num >> cp >> x >> y >> m;
		for(int j = 1; j <= num; ++j){
			if(curt > cp)++cur_d;
			if(curnum <= 200000){
				sm[++curnum].x = cp;
				sm[curnum].til = cur_d;
				sm[curnum].id = i;
			}
			curt = cp;
			cp = (cp * x + y) % m;
		}
		res = max(res, cur_d);
	}
	sort(sm + 1, sm + curnum + 1, cmp);
	if(curnum > 200000)curnum = 0;
	printf("%d\n", res);
	for(int i = 1; i <= curnum; ++i)
		printf("%d %d\n", sm[i].x, sm[i].id);
	return 0;
}