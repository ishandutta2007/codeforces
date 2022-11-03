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

struct Lemm {
	int mass;
	int vel;
	int name;
	inline bool operator< (const Lemm &x) const {
		if (mass != x.mass) return mass < x.mass;
		if (vel != x.vel) return vel < x.vel;
		return name < x.name;
	}
};

int n, k, h;
Lemm arr[SIZE];
int ass[SIZE];

bool Solve(double maxt) {
	int p = 0;
	for (int i = 0; i<n; i++) {
		double can = arr[i].vel * maxt;
		if (can >= (p+1)*h) {
			ass[p++] = i;
			if (p == k) return true;
		}
	}
	return false;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d%d", &n, &k, &h);
	for (int i = 0; i<n; i++) arr[i].name = i;
	for (int i = 0; i<n; i++) scanf("%d", &arr[i].mass);
	for (int i = 0; i<n; i++) scanf("%d", &arr[i].vel);
	sort(arr, arr+n);

    double left = 0.0;
	double right = 1000000100.0;
	for (int q = 0; q<100; q++) {
		double mid = (left + right) * 0.5;
		if (Solve(mid))
			right = mid;
		else
			left = mid;
	}
	Solve(right);

	for (int i = 0; i<k; i++) printf("%d ", arr[ass[i]].name + 1);

	return 0;
}