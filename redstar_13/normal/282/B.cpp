#include <bits/stdc++.h>



#define inf 0x3f3f3f3f

#define MOD 1000000007

#define pb push_back

#define sq(x) ((x)*(x))

#define x first

#define y second

#define eps 1e-8

#define bpt(x) (__builtin_popcount(x))

#define bptl(x) (__builtin_popcountll(x))

#define bit(x, y) (((x)>>(y))&1)

#define bclz(x) (__builtin_clz(x))

#define bclzl(x) (__builtin_clzll(x))

#define bctz(x) (__builtin_ctz(x))

#define bctzl(x) (__builtin_ctzll(x))



using namespace std;

typedef long long INT;

typedef vector<int> VI;

typedef pair<int, int> pii;

typedef pair<pii, int> pi3;

typedef double DO;



template<typename T, typename U> inline void smin(T &a, U b) {if (a>b) a=b;}

template<typename T, typename U> inline void smax(T &a, U b) {if (a<b) a=b;}



#define NN 1000011



int main() {

	int n,i,j;

	cin>>n;

	

	INT sum=0;

	for(i=0; i<n; i++){

		int a,b;

		scanf("%d%d", &a, &b);

		sum+=a;

	}

	

	int ok=1;

	for(i=0; i<=n; i++){

		INT L=(INT)1000*i-500;

		INT R=(INT)1000*i+500;

		if(sum>=L && sum<=R) {

			char key='A';

			for(j=1; j<=n; j++){

				if(j==n-i+1) key='G';

				putchar(key);

			}

			ok=0;

			return 0;

		}

	}

	if(ok) puts("-1");



	return 0;

}