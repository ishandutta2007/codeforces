#include <bits/stdc++.h>

using namespace std;



inline char nc(){

  static char buf[100000],*p1=buf,*p2=buf;

  if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }

  return *p1++;

}



inline int getint(){

  int x;

  char c=nc(),b=1;

  if(c == -1)

    return 0;

  for (;!(c>='0' && c<='9');c=nc()) if (c=='-') b=-1;

  for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;

  return x;

}



#define N 100005



#define pb push_back

#define x first

#define y second



template <class T> bool chkmin(T &a, T b) { return a > b ? a = b, 1 : 0; }

template <class T> bool chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

const int inf = 1e9;

const ll linf = 1e18;

const int mod = 1e9 + 7;

const double eps = 1e-7;



int runs, p[N], phi[N], mu[N];



void ppm() {

	phi[1] = 1, mu[1] = 1;

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

	}

}



int n, m;



int main() {

    ppm();

    scanf("%d %d", &n, &m);

    ll cnt = 0;

    for (int i = 1; i <= n; i ++) cnt += phi[i];

    if (m < n - 1 || m > cnt - 1) {

        return puts("Impossible"), 0;

    }

    printf("Possible\n");

    for (int i = 2; i <= n; i ++) printf("1 %d\n", i);

    int runs = m - (n - 1);

    for (int i = 2; i <= n && runs; i ++)

    for (int j = i + 1; j <= n && runs; j ++) {

        if (__gcd(i, j) == 1) {

            printf("%d %d\n", i, j);

            runs --;

        }

    }

    return 0;

}