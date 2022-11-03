#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

const int MAXN = 2E3 + 10;

int n, h;
double p, q;
int a[MAXN];

bool vis[MAXN][MAXN][2][2];
double f[MAXN][MAXN][2][2];

int left[MAXN], right[MAXN];

double getValue(int l, int r, int dl, int dr){
	if (l > r)
		return 0.0;

	if (!vis[l][r][dl][dr]){
		vis[l][r][dl][dr] = true;
		int l0 = a[l] - a[l - 1] - (dl ? h : 0);
		int r0 = a[r + 1] - a[r] - (dr ? h : 0);

		double res;
		//left left
		f[l][r][dl][dr] += p * (getValue(l + 1, r, 0, dr) + min(l0, h));

		//left right
		if (r < right[l])
			f[l][r][dl][dr] += q * (a[r] - a[l] + min(r0, h));
		else
			f[l][r][dl][dr] += q * (getValue(right[l], r, 1, dr) + a[right[l] - 1] - a[l] + h);

		//right right
		f[l][r][dl][dr] += q * (getValue(l, r - 1, dl, 0) + min(r0, h));

		//right left
		if (left[r] < l)
			f[l][r][dl][dr] += p * (a[r] - a[l] + min(l0, h));
		else
			f[l][r][dl][dr] += p * (getValue(l, left[r], dl, 1) + a[r] - a[left[r] + 1] + h);
	}

	return f[l][r][dl][dr];
}

int main(){
	scanf("%d%d%lf", &n, &h, &p);
	p *= 0.5;
	q = 0.5 - p;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	a[0] = a[1] - h;
	a[n + 1] = a[n] + h;

	left[1] = 0;
	for (int i = 2; i <= n; ++i)
		left[i] = a[i] - h < a[i - 1] ? left[i - 1] : i - 1;
	right[n] = n + 1;
	for (int i = n - 1; i; --i)
		right[i] = a[i + 1] < a[i] + h ? right[i + 1] : i + 1;

	printf("%.10lf\n", getValue(1, n, 0, 0));
	return 0;
}