#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
struct team {
	long long t, w; int id;
};
bool operator<(const team& t1, const team& t2) {
	return t1.t > t2.t;
}
int n; team z[300009];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		z[i].id = i;
		scanf("%lld%lld", &z[i].t, &z[i].w);
	}
	sort(z, z + n);
	priority_queue<long long, vector<long long>, greater<long long> > que;
	int r = 0;
	for (int i = 0; i < n; i++) {
		if (z[i].id == 0) r = i;
	}
	int ptr = 0, ret = 1, res = r + 1; long long cap = z[r].t;
	for(int i = 0; i < n * 2; i++) {
		while (ptr < n && z[ptr].t > cap) {
			if(ptr != r) que.push(z[ptr].w - z[ptr].t + 1);
			if(ptr++ != r) ret++;
		}
		res = min(res, ret);
		if (que.size() && cap >= que.top()) {
			cap -= que.top();
			que.pop(); ret--;
		}
	}
	printf("%d\n", res);
	return 0;
}