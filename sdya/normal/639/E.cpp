#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 160000;
int n;
int p[maxN], cp[maxN], t[maxN];
int order[maxN], b[maxN];

long long q[maxN];
long long T = 0;

bool comp(int x, int y) {
	if ((long long)(p[x]) * (long long)(t[y]) < (long long)(p[y]) * (long long)(t[x])) {
		return false;
	}
	if ((long long)(p[x]) * (long long)(t[y]) > (long long)(p[y]) * (long long)(t[x])) {
		return true;
	}
	return p[x] < p[y];
}

double values[maxN];
int u[maxN];

double ft[maxN];

void update(int k, double value) {
	for (int i = k; i < maxN; i |= (i + 1)) {
		ft[i] = max(ft[i], value);
	}
}

double get(int k) {
	double res = 0.0;
	for (int i = k; i >= 0; i = (i & (i + 1)) - 1) {
		res = max(res, ft[i]);
	}
	return res;
}

bool check(double c) {
	for (int i = 0; i < n; ++i) {
		int v = order[i];
		values[i] = (double)(p[v]) - c * (double)(p[v]) * (double)(q[v]) / (double)(T);
		u[i] = cp[v];
	}
	for (int i = 0; i < maxN; ++i) {
		ft[i] = 0.0;
	}

	for (int i = 0; i < n; ++i) {
		double score = get(u[i] - 1);
		if (score > values[i]) {
			return false;
		}
		update(u[i], values[i]);
	}

	vector < pair < int, double > > w;

	for (int i = 0; i < maxN; ++i) {
		ft[i] = 0.0;
	}

	int index = 0;
	long long prevsum = 0;
	while (index < n) {
		int j = index;
		for (int i = j; i < n; ++i) {
			int x = order[index];
			int y = order[i];
			if ((long long)(p[x]) * (long long)(t[y]) == (long long)(p[y]) * (long long)(t[x])) {
				j = i;
			} else {
				break;
			}
		}

		long long sum = 0;
		for (int i = index; i <= j; ++i) {
			sum += (long long)(t[order[i]]);
		}

		for (int i = index; i <= j; ++i) {
			int y = order[i];
			long long q2 = prevsum + sum;
			double v2 = (double)(p[y]) - c * (double)(p[y]) * (double)(q2) / (double)(T);

			double score = get(cp[y] - 1);
			if (score > v2) {
				return false;
			}
		}

		for (int i = index; i <= j; ++i) {
			int x = order[i];
			long long q1 = prevsum + t[x];
			double v1 = (double)(p[x]) - c * (double)(p[x]) * (double)(q1) / (double)(T);
			update(cp[x], v1);
		}

		for (int i = index + 1; i <= j; ++i) {
			int x = order[i - 1];
			int y = order[i];
			if (p[x] < p[y]) {
				long long q1 = prevsum + t[x];
				long long q2 = prevsum + sum;

				double v1 = (double)(p[x]) - c * (double)(p[x]) * (double)(q1) / (double)(T);
				double v2 = (double)(p[y]) - c * (double)(p[y]) * (double)(q2) / (double)(T);

				if (v1 > v2) {
					return false;
				}
			}
		}

		prevsum += sum;
		index = j + 1;
	}

	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	vector < int > a;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
		a.push_back(p[i]);
	}
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	for (int i = 0; i < n; ++i) {
		cp[i] = lower_bound(a.begin(), a.end(), p[i]) - a.begin();
	}

	for (int i = 0; i < n; ++i) {
		scanf("%d", &t[i]);
		order[i] = i;
	}
	sort(order, order + n, comp);
	T = 0;
	for (int i = 0; i < n; ++i) {
		int v = order[i];
		T += (long long)(t[v]);
		q[v] = T;
	}

	double left_bound = 0.0, right_bound = 1.0;
	for (int i = 0; i < 35; ++i) {
		double middle = (left_bound + right_bound) / 2.0;
		if (check(middle)) {
			left_bound = middle;
		} else {
			right_bound = middle;
		}
	}

	printf("%.10lf\n", (left_bound + right_bound) / 2.0);

	return 0;
}