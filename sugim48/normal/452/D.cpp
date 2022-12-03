#include <algorithm>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int N;
int bit1[11000001], bit2[11000001], bit3[11000001];

int sum(int bit[], int i) {
	int res = 0;
	while (i > 0) {
		res += bit[i];
		i -= i & -i;
	}
	return res;
}

void add(int bit[], int i, int x) {
	while (i <= 11000000) {
		bit[i] += x;
		i += i & -i;
	}
}

int main() {
	int k, n1, n2, n3, t1, t2, t3;
	scanf("%d%d%d%d%d%d%d", &k, &n1, &n2, &n3, &t1, &t2, &t3);
	int t = 1;
	for (; k > 0; k--) {
		int lb = t - 1, ub = 10000000;
		while (ub - lb > 1) {
			int mid = (lb + ub) / 2;
			if (sum(bit1, mid) < n1 && sum(bit2, mid + t1) < n2 && sum(bit3, mid + t1 + t2) < n3)
				ub = mid;
			else
				lb = mid;
		}
		t = ub;
		add(bit1, t, 1);
		add(bit1, t + t1, -1);
		add(bit2, t + t1, 1);
		add(bit2, t + t1 + t2, -1);
		add(bit3, t + t1 + t2, 1);
		add(bit3, t + t1 + t2 + t3, -1);
	}
	printf("%d\n", t + t1 + t2 + t3 - 1);
}