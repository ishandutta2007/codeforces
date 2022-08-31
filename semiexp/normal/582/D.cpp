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
#define MOD 1000000007
#define ADD(X,Y) ((X) = (int)((i64)(X) + (i64)(Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int ford(int n, int p)
{
	int ret = 0;
	while (n) {
		ret += n / p;
		n /= p;
	}
	return ret;
}

int P, A;
char S[1010];
vector<i64> seq;

void mult(int m)
{
	i64 kuri = 0;
	for (int i = 0; i < seq.size(); ++i) {
		kuri += seq[i] * m;
		seq[i] = kuri % P;
		kuri /= P;
	}
	while (kuri) {
		seq.push_back(kuri % P);
		kuri /= P;
	}
}
void add(int v)
{
	i64 kuri = v;
	for (int i = 0; i < seq.size(); ++i) {
		kuri += seq[i];
		seq[i] = kuri % P;
		kuri /= P;
	}
	while (kuri) {
		seq.push_back(kuri % P);
		kuri /= P;
	}
}

int dp[2][3333][3][3];
int N;

void clr(int t)
{
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				dp[t][i][j][k] = 0;
			}
		}
	}
}

int main()
{
	scanf("%d%d", &P, &A);
	scanf("%s", S);

	seq.push_back(0LL);
	for (int i = 0; S[i]; ++i) {
		mult(10);
		add(S[i] - '0');
	}

	N = seq.size();

	int t = 1;
	clr(t);
	dp[t][0][1][1] = 1;

	for (int i = 0; i < N; ++i) {
		clr(1 - t);

		i64 cv = seq[i];
		i64 k1 = (cv * (cv - 1) / 2 % MOD);
		i64 k2 = ((cv * P - cv - cv * (cv - 1) / 2) % MOD);
		i64 k3 = (((P - 1) * (P - cv - 1) - (P - cv - 1) * (P - cv - 2) / 2) % MOD);
		i64 k4 = ((P - cv - 1) * (P - cv - 2) / 2 % MOD);
		for (int j = 0; j <= i; ++j) {
			for (int k = 0; k < 3; ++k) {
				if (j > 0 && k == 1) continue;
				for (int l = 0; l < 3; ++l) {
					if (true) {
						ADD(dp[1 - t][j + (k == 2 ? 1 : 0)][k][2], dp[t][j][k][l] * cv); // dw = upp < cv
						ADD(dp[1 - t][j + (k == 2 ? 1 : 0)][k][l], dp[t][j][k][l] * 1); // dw = upp < cv
						ADD(dp[1 - t][j + (k == 2 ? 1 : 0)][k][0], dp[t][j][k][l] * (P - cv - 1)); // dw = upp > cv
					}
					// upp < cv
					ADD(dp[1 - t][j][0][2], dp[t][j][k][l] * k1); // dw < upp < cv
					ADD(dp[1 - t][j + 1][2][2], dp[t][j][k][l] * k2); // dw > upp < cv

					// upp == cv
					ADD(dp[1 - t][j][0][l], dp[t][j][k][l] * cv); // dw < upp == cv
					ADD(dp[1 - t][j + 1][2][l], dp[t][j][k][l] * (P - cv - 1)); // dw > upp < cv

					// upp > cv
					ADD(dp[1 - t][j][0][0], dp[t][j][k][l] * k3); // dw < upp > cv
					ADD(dp[1 - t][j + 1][2][0], dp[t][j][k][l] * k4); // dw > upp > cv
				}
			}
		}
		t = 1 - t;
	}

	i64 ret = 0;
	for (int i = 0; i <= N; ++i) if (i >= A) {
		ADD(ret, dp[t][i][1][1]);
		ADD(ret, dp[t][i][1][2]);
		ADD(ret, dp[t][i][0][1]);
		ADD(ret, dp[t][i][0][2]);
	}
	printf("%lld\n", ret);

	/*
	int n, p;
	scanf("%d%d", &n, &p);
	for (int i = 0; i <= n; ++i) printf("ord_%d C(%d, %d) = %d\n", p, n, i, ford(n, p) - ford(i, p) - ford(n - i, p));
	*/
	return 0;
}