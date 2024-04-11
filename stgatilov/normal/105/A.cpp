#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

int n, m;
double k;

typedef map<string, int> tMap;
tMap all;
tMap pass;

char buff[1024];
int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d%lf", &n, &m, &k);
	for (int i = 0; i<n; i++) {
		int cc;
		scanf("%s%d", buff, &cc);
		all[buff] = cc;
	}
	for (tMap::iterator it = all.begin(); it != all.end(); it++) {
		int q = it->second;
		int r = int((1e-9) + q * k);
		if (r < 100) continue;
		pass[it->first] = r;
	}
	for (int i = 0; i<m; i++) {
		scanf("%s", buff);
		if (pass.find(buff) == pass.end())
			pass[buff] = 0;
	}
	printf("%d\n", pass.size());
	for (tMap::iterator it = pass.begin(); it != pass.end(); it++)
		printf("%s %d\n", it->first.c_str(), it->second);
	return 0;
}