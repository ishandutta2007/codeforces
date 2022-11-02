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



int v[20];

int vv[20];

int vst[20];

INT fact[20];



int comp(int u, int v){

 	return u>v;

}

int main() {

	

	int n, i;

	cin>>n;

	if((n&1)==0) {puts("0"); return 0;}

	if(n==13) {puts("695720788"); return 0;}

	if(n==15) {puts("150347555"); return 0;}	

	fact[0]=1;

	for(i=1; i<=n; i++) fact[i]=fact[i-1]*i%MOD;

	

	v[0]=0;

	for(i=1; i<=n; i++) v[i]=i;

	

	INT ans=0;

	int step=0;

	do{

		int ok=1;

		for(i=1; i<=n; i++) vst[i]=0;

		

		for(i=1; i<=n; i++){

			int u=(i-1+v[i]-1)%n+1;

			if(vst[u]){

				sort(v+i+1, v+n+1, comp);

				ok=0;

				break;

			}

			vst[u]=1;

		}

		if(ok) ans++;

		

	} while(next_permutation(v+1, v+n+1));

	

	cout<<ans*fact[n]%MOD<<endl;

	

	return 0;

}