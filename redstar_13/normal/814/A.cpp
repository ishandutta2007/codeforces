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



using namespace std;

typedef long long INT;

typedef vector<int> VI;

typedef pair<int, int> pii;

typedef double DO;



template<typename T, typename U> inline void smin(T &a, U b) {if (a>b) a=b;}

template<typename T, typename U> inline void smax(T &a, U b) {if (a<b) a=b;}

#define MM 300

int a[MM],b[MM],n,k;



int main() {

//	freopen("in.in", "r", stdin);

//	freopen("in.out", "w", stdout);

	scanf("%d%d", &n ,&k);

	for(int i=0;i<n;i++) scanf("%d",a+i);

	for(int i=0;i<k;i++) scanf("%d", b+i);

	if(k==1){

		int f=0;

		for(int i=0;i<n;i++) if(a[i]==0) a[i]=b[0];

		for(int i=1;i<n;i++) if(a[i-1]>=a[i]){f=1;break;}

		if(!f) puts("No");

		else puts("Yes");

	}

	else puts("Yes");

	return 0;

}