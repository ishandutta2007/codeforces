#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define MOD 1000000007
#define MT make_tuple
#define PB push_back
typedef long long ll;

int N, X;
typedef long double ld;
ld v[128][128], o[128][128], ans[128][128], p[128];

int main () {
	scanf("%d %d", &N, &X);
	ans[0][0] = (ld) 1.;
	fo(i, 0, X+1) {
		double in;
		scanf("%lf", &in);
		p[i] = (ld) in;
		fo(s, 0, 128) {
			assert((i^s) < 128);
			v[s][i^s] += in;
		}
	}
	while (N) {
		if (N&1) {
			fo(i, 0, 128) fo(j, 0, 128) o[i][j] = ans[i][j], ans[i][j] = 0;
			fo(i, 0, 128) fo(j, 0, 128) fo(m, 0, 128) {
				ans[i][j] += o[i][m] * v[m][j];
			}
		}
		fo(i, 0, 128) fo(j, 0, 128) o[i][j] = v[i][j], v[i][j] = 0;
		fo(i, 0, 128) fo(j, 0, 128) fo(m, 0, 128) {
			v[i][j] += o[i][m] * o[m][j];
		}
		N /= 2;
	}
	printf("%.10lf\n", 1.0 - double(ans[0][0]));
	return 0;
}