#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

long long solve(long long a, long long b, long long k) {
	const int period = 2 * 360360;
	vector < long long > d(period + 1, -1);
	queue < long long > q;

	q.push(0);
	d[0] = 0;

	while (!q.empty()) {
		long long current = q.front();
		q.pop();

		if (current + 1 <= period && d[current + 1] == -1) {
			d[current + 1] = d[current] + 1;
			q.push(current + 1);
		}

		current += b;
		for (int i = 2; i <= k; ++i) {
			if (current % i == 0) {
				for (int j = 1; j < i; ++j) {
					if (current + j > period + b) {
						break;
					}
					if (d[current + j - b] == -1) {
						q.push(current + j - b);
						d[current + j - b] = d[current - b] + 1;
					}
				}
			}
		}
	}

	if (a - b <= period) {
		return d[a - b];
	} else {
		long long need = (a - b) % (period / 2);
		return d[need] + (d[need + period / 2] - d[need]) * ((a - b) / (period / 2));
	}
}

int main() {
	long long a, b, k;
	while (cin >> a >> b >> k) {
		cout << solve(a, b, k) << endl;
	}
	return 0;
}