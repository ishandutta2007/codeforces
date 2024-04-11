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

#define maxn 1200

using namespace std;

long long dist_h[maxn], dist_v[maxn];
long long cc[maxn][maxn];
int n, m, li, lj;
long long res;
long long sum_h[maxn], sum_v[maxn];

long long dd(const int &x, const int &y){
	long long pp = (4 * (x - y) - 2);
	return pp * pp;
}

int main(){
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j =	1; j <= m; ++j){
			int cur_c;
			cin >> cur_c;
			cc[i][j] = cur_c;
			sum_h[i] += cc[i][j];
			sum_v[j] += cc[i][j];
		}

	for(int i = 0; i <= n; ++i){
		dist_h[i] = 0;
		for(int j = 1; j <= n; ++j)
			dist_h[i] += dd(j, i) * sum_h[j];
	}

	for(int i = 0; i <= m; ++i){
		dist_v[i] = 0;
		for(int j = 1; j <= m; ++j)
			dist_v[i] += dd(j, i) * sum_v[j];
	}

	res = dist_h[0] + dist_v[0];
	li = lj = 0;
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
			if(dist_h[i] + dist_v[j] < res){
				res = dist_h[i] + dist_v[j];
				li = i;
				lj = j;
			}

	cout << res << '\n' << li << ' ' << lj << '\n';

	return 0;
}