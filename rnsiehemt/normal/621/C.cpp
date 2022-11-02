#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

typedef double real;
const int MaxN = 100005;

int N, P, l[MaxN], r[MaxN];
real ans;

int get2(int a) {
	return a/P;
}
real get(int a, int b) {
	return double(get2(b) - get2(a-1)) / (b - (a-1));
}

int main()
{
	scanf("%d%d", &N, &P);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &l[i], &r[i]);
	}
	for (int i = 0; i < N; i++) {
		int j = (i+1)%N;
		real p = get(l[i], r[i]);
		real q = get(l[j], r[j]);
		//printf("%lf %lf\n", p, q);
		ans += 2000 * (1-((1-p)*(1-q)));
	}
	printf("%.8lf\n", ans);
}