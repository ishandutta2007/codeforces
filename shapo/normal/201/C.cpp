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

#define maxn 100500

using namespace std;

int n;
long long cur_i[maxn];
long long lb[maxn], ln[maxn], rb[maxn], rn[maxn];

inline long long md(const long long &mdd){return(mdd % 2 == 0) ? mdd : (mdd - 1);}

int main(){
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i < n; ++i){
		int cc;
		cin >> cc;
		cur_i[i] = cc;
	}

	lb[1] = ln[1] = 0;
	for(int i = 2; i <= n; ++i){
		long long xx = cur_i[i - 1];
		ln[i] = md(xx - 1) + 1 + max(ln[i - 1], lb[i - 1]);
		if(xx == 1)lb[i] = 0;
		else lb[i] = lb[i - 1] + md(xx);
	}

	rb[n] = rn[n] = 0;
	for(int i = n - 1; i >= 1; --i){
		long long xx = cur_i[i];
		rn[i] = md(xx - 1) + 1 + max(rn[i + 1], rb[i + 1]);
		if(xx == 1)rb[i] = 0;
		else rb[i] = rb[i + 1] + md(xx);
	}

	long long res = 0;
	for(int i = 1; i <= n; ++i)
		res = max(res, max(ln[i] + rb[i], lb[i] + rn[i]));

	cout << res << '\n';

	return 0;
}