#include <bits/stdc++.h>
using namespace std;
#define N 1000001
#define inf 1000000000
#define ep 1e-9
#define mp make_pair
#define pb push_back
#define ll long long
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;
const int mod = 1e9 + 7;

int n, a, b[N], d[N];

int runs, p[N], phi[N], mu[N], bi[N];
void ppm() {
	phi[1] = 1, mu[1] = 1, bi[1] = 1;
	for (int i = 2; i < N; i ++) {
		if (!phi[i]) p[++runs] = i, phi[i] = i - 1, mu[i] = -1;
		for (int j = 1; j <= runs && i * p[j] < N; j ++) {
			int k = i * p[j];
			phi[k] = phi[i] * (p[j] - 1);
			if (i % p[j] == 0) {
				phi[k] = phi[i] * p[j]; break;
			}
			mu[k] = -mu[i];
		}
		bi[i] = 2ll * bi[i-1] % mod;
	}
}

int main() {
	ppm();
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a), b[a] ++;
	for (int i = 2; i < N; i ++) for (int j = i; j < N; j += i) d[i] += b[j];
	int ans = 0;
	for (int i = 2; i < N; i ++) {
		ans += 1ll * d[i] * bi[d[i]] % mod * (phi[i] - mu[i]) % mod;
		ans %= mod;
	}
	cout<<ans<<endl;
    return 0;
}