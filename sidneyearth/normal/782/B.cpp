#include<bits/stdc++.h>
using namespace std;
typedef pair<double, int> Pair;
const int maxn = 1000100;
Pair p[2 * maxn];
const double eps = 1e-12;
double x[maxn], v[maxn];
int main(){
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%lf", &x[i]);
	for(int i = 0; i < n; i++)
		scanf("%lf", &v[i]);
	double l = 0, r = 1e10;
	while(r - l > 1e-7){
		double m = (l + r) / 2;
		for(int i = 0; i < n; i++){
			p[i] = Pair(x[i] - v[i] * m - eps, 1);
			p[i+n] = Pair(x[i] + v[i] * m + eps, -1);
		}
		sort(p, p + 2 * n);
		int cnt = 0, mx = 0;
		for(int i = 0; i < 2 * n; i++){
			cnt += p[i].second;
			if(cnt > mx) mx = cnt;
		}
		if(mx == n) r = m;
		else l = m;
	}
	printf("%.7lf\n", l);
	return 0;
}