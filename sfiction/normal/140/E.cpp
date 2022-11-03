/*
 * ID: Sfiction
 * OJ: ZOJ
 * PROB: 140E
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1E6 + 10, MAXL = 5E3 + 10;

int n, m, p;
int maxl;
int l[MAXN];

unsigned int s[MAXL][MAXL];
long long A[MAXL], F[MAXL];
vector<long long> d[MAXN];

int main(){
	scanf("%d%d%d", &n, &m, &p);
	maxl = 0;
	for (int i=1;i<=n;++i){
		scanf("%d", &l[i]);
		maxl = max(maxl, l[i]);
	}

	//calculate s[i][j], ways of color length i by using j colors following the first rule.
	s[0][0] = 1;
	for (int i=1;i<=maxl;++i)
		for (int j=1;j<=i;++j){
			//use new color, use color used before but not the pre one.
			s[i][j] = (s[i - 1][j - 1] + (long long)s[i - 1][j] * (j - 1)) % p;
		}

	//calculate A(m)[i] = Mult(1, i, m * (m - 1) *...*(m - i + 1));
	A[0] = 1;
	F[0] = 1;
	for (int i=1;i<=maxl;++i){
		A[i] = (A[i - 1] * (m - i + 1)) % p;
		F[i] = (F[i - 1] * i) % p;
	}

	//d[i][j], ways of compose the first i layers ans use exactly j colors in ith layer.
	//d[i][0] is the sum of d[i][k].
	l[0] = 0;
	d[0].push_back(1);
	for (int i=1;i<=n;++i){
		d[i].push_back(0);
		for (int j=1;j<=l[i];++j){
			d[i].push_back((((A[j] * s[l[i]][j]) % p) * d[i - 1][0]) % p);
		}

		for (int j=1;j<=l[i-1] && j<=l[i];++j){
			d[i][j] = (d[i][j] + p - ((F[j] * s[l[i]][j]) % p * d[i - 1][j]) % p) % p;
		}

		for (int j=1;j<=l[i];++j){
			d[i][0] = (d[i][0] + d[i][j]) % p;
		}

		vector<long long>().swap(d[i - 1]);
	}

	printf("%d\n", int(d[n][0]));

	return 0;
}