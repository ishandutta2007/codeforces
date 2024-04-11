#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 1000010
double F[N];

double logC(int n, int k) {
	return F[n]-F[k]-F[n-k];
}

int main()
{
	F[0] = 0;
	for (int i = 1; i < N; i ++) 
		F[i] = F[i-1]+log(i);
	int n,m;
	cin >> n >> m;
	double S = 0;
	for (int k = 0; k <= min(n,m); k ++) {
		double T = 0;
		T -= log(n);
		T += logC(m,k);
		T += logC(m*(n-1),n-k);
		T -= logC(m*n,n);
		T += 2*log(k);
		S += exp(T);
	}
	printf ("%.9lf\n",S);
	return 0;
}