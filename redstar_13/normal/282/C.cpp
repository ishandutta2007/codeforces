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



#define NN 1000111



char s[NN], t[NN];



int main() {

	

	cin>>s>>t;

	int ls=strlen(s), lt=strlen(t);

	if(ls!=lt) {puts("NO"); return 0;}

	

	int cnt[2]={0,};

	

	for(int i=0; i<ls; i++){

		if(s[i]=='1') cnt[0]++;

		if(t[i]=='1') cnt[1]++;

	}

	

	if(cnt[0]==0 && cnt[1]!=0) puts("NO");

	else if(cnt[1]==0 && cnt[0]!=0) puts("NO");

	else puts("YES");

	return 0;

}