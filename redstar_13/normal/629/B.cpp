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



#define NN 5555

int a[NN], b[NN];

char c[NN];



int cnt[2][400];

int main() {

	int n,i,j;

	cin>>n;

	for(i=0; i<n; i++){

		scanf(" %c %d %d", c+i, a+i, b+i);

		int flag;

		if(c[i]=='F') flag=0;

		else flag=1;

		for(j=a[i]; j<=b[i]; j++){

			cnt[flag][j]++;

		}

	}

	

	int mx=0;

	for(i=1; i<=366; i++){

		int val=2*min(cnt[0][i], cnt[1][i]);

		if(val>mx) mx=val;

	}

	cout<<mx<<endl;



	return 0;

}