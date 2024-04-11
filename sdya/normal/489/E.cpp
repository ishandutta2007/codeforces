#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;

const int maxN = 1100;
int n, l;
int x[maxN], y[maxN];

double d[maxN];
double v[maxN][maxN];
int p[maxN], q[maxN];

bool check(double value) {
	for (int i = 0; i < maxN; ++i) {
		d[i] = 1e50;
	}
	
	d[0] = 0.0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			double score = d[j] + v[j][i] - value * (double)(y[i]);
			if (score < d[i]) {
				d[i] = score;
				p[i] = j;
			}
		}
	}
	if (d[n] <= 0) {
		for (int i = 0; i <= n; ++i) {
			q[i] = p[i];
		}
		return true;
	}
	return false;
}

void print() {
	vector < int > path;
	int x = n;
	while (x) {
		path.push_back(x);
		x = q[x];
	}
	reverse(path.begin(), path.end());
	for (int i = 0; i < path.size(); ++i) {
		printf("%d ", path[i]);
	}
	printf("\n");
}

int main() {
	cin >> n >> l;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			v[i][j] = abs(abs(x[j] - x[i]) - l);
			v[i][j] = sqrt(v[i][j]);
		}
	}
	double left_bound = 0.0, right_bound = 1e6;
	for (int iters = 0; iters < 50; ++iters) {
		double middle = (left_bound + right_bound) / 2;
		if (check(middle)) {
			right_bound = middle;
		} else {
			left_bound = middle;
		}
	}
	print();

	return 0;
}