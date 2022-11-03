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
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int SIZE = 100<<10;

int n, l, v1, v2;
double w;
double arr[3*SIZE];

struct Event {
	double tim;
	bool isr;
	bool fin;
	bool operator< (const Event &e) const {
		return tim < e.tim;
	}
};
vector<Event> evs;

double ans[SIZE];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d%d%d", &n, &l, &v1, &v2);
	w = (double(v2) * l) / (0.0 + v1 + v2);
	for (int i = 0; i<n; i++) scanf("%lf", &arr[i]);
	for (int i = 0; i<=2*n; i++) arr[n+i] = arr[i] + 2.0 * l;

	int curr = 0;
	for (int i = 0; i<2*n; i++) {
		Event e;
		e.fin = false;
		e.isr = false;
		e.tim = arr[i];
		evs.push_back(e);

		if (arr[i] >= w) {
			e.isr = true;
			e.tim = arr[i] - w;
			evs.push_back(e);
		}
		else {
			curr++;
		}
	}
	Event ff;
	ff.tim = 2.0*l;
	ff.fin = true;
	evs.push_back(ff);
	sort(evs.begin(), evs.end());

	double now = 0.0;
	for (int i = 0; i<evs.size(); i++) {
		double dt = evs[i].tim - now;
		ans[curr] += dt / (2.0*l);
		now = evs[i].tim;

		if (evs[i].fin) break;

		if (evs[i].isr)
			curr++;
		else
			curr--;
	}

	for (int i = 0; i<=n; i++) printf("%0.18lf\n", ans[i]);

	return 0;
}