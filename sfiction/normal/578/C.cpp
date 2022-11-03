#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2E5 + 10;
const double MAXM = 1E4 + 10;

int n;
int a[MAXN];

double count(double x){
	double summin = MAXN * MAXM, summax = -MAXN * MAXM;
	double premin = 0, premax = 0;
	double sum = 0;
	for (int i = 1; i <= n; ++i){
		sum += a[i] - x;
		summin = min(summin, sum - premax);
		summax = max(summax, sum - premin);
		premin = min(premin, sum);
		premax = max(premax, sum);
	}
	return max(summax, -summin);
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	double high = MAXM, low = -MAXM, mid1, mid2;
	for (int i = 0; i < 100; ++i){
		mid1 = (high * 2 + low) / 3;
		mid2 = (high + low * 2) / 3;
		if (count(mid1) > count(mid2))
			high = mid1;
		else
			low = mid2;
	}
	printf("%.12lf\n", count((high + low) / 2));
	return 0;
}