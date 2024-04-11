/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 552D
 */
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 2E3 + 10, MAXM = 200 + 10;

int n;
int x[MAXN], y[MAXN];

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

pair<int, int> get_pair(int a, int b){
	if (a == 0)
		return make_pair(0, 1);
	
	int d = gcd(a, b);
	a /= d;
	b /= d;
	if (a < 0){
		a *= -1;
		b *= -1;
	}

	return make_pair(a, b);
}

int main(){
	scanf("%d", &n);
	for (int i=0;i<n;++i)
		scanf("%d%d", &x[i], &y[i]);

	ll sum = 0;
	for (int i=0;i<n;++i){
		vector<PII> lst;
		lst.reserve(n - 1);
		for (int j=0;j<n;++j)
			if (i != j)
				lst.push_back(get_pair(x[i] - x[j], y[i] - y[j]));

		sort(lst.begin(), lst.end());

		for (int k, j = 0; j < n - 1; j = k){
			for (k = j + 1; k < n - 1 && lst[j] == lst[k]; ++k);
			sum += (k - j) * (n - 1 - k + j);
		}
	}
	sum /= 6;

	printf("%I64d", sum);

	return 0;
}