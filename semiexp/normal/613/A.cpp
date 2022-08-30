#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, x, y;
int px[101010], py[101010];

int main()
{
	scanf("%d%d%d", &N, &x, &y);
	for (int i = 0; i < N; ++i) {
		scanf("%d%d", px + i, py + i);
		px[i] -= x;
		py[i] -= y;
	}
	px[N] = px[0];
	py[N] = py[0];

	double dmin = 1e10, dmax = 0;
	for (int i = 0; i < N; ++i) {
		double da = sqrt((double)px[i] * px[i] + (double)py[i] * py[i]);
		dmax = max(dmax, da);
		dmin = min(dmin, da);
		double db = sqrt((double)px[i + 1] * px[i + 1] + (double)py[i + 1] * py[i + 1]);
		double dc = sqrt((double)(px[i + 1] - px[i]) * (px[i + 1] - px[i]) + (double)(py[i + 1] - py[i]) * (py[i + 1] - py[i]));
		if (db * db + dc * dc > da * da && dc * dc + da * da > db * db) {
			double tri = fabs((double)px[i] * py[i + 1] - (double)px[i + 1] * py[i]);
			dmin = min(dmin, tri / dc);
		}
	}
//	printf("%f %f\n", dmin, dmax);

	printf("%.10f\n", 3.14159265358979323846 * (dmax * dmax - dmin * dmin));
	return 0;
}