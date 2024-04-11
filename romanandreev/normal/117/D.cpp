#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <climits>
#include <cstring>
#include <complex>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;


#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )

#ifdef WIN32
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

ll n,l,r,u,v;
int m;
ll md;
ll obr(ll x){
	x=x%md;
	if (x<0) x+=md;
	return x;
}
ll sum(ll x){
	if (x%2==0)
	return obr((obr(x/2)*obr(x+1)));
	return obr((obr(x)*obr((x+1)/2)));
}
ll calc2(ll l1,ll r1,ll c,ll k){
	if (k>v){
		return 0;
	}
	if ((r1-l1)*c+k<u){
		return 0;
	}
	ll f1=(v-k)/c;
/*	ll l,r,m;
	l=0;
	r=r1-l1;
	while (l<r){
		m=(l+r)>>1;
		if (m*c+k>=u){
			r=m;
		} else l=m+1;
	}*/
	//ll f2=l;
	ll f2=(u-k+c-1)/c;
	f1=min(f1,r1-l1);
	f1=max(f1,0LL);
	f2=min(f2,r1-l1);
	f2=max(f2,0LL);
	if (f2>f1) return 0;
	return obr(obr(k)*obr(f1-f2+1)+obr(c)*obr( sum(f1)-sum(f2-1)  ));
}
ll calc(ll l1,ll r1,ll c,ll k){
	if (r1<l || r<l1) return 0;
	if (l<=l1 && r1<=r){
		return calc2(l1,r1,c,k);
	}
	ll m1=(l1+r1)/2;
	return (calc(l1,m1,c*2,k)+calc(m1+1,r1,c*2,k+c))%md;
}
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	scanf(INT64"%d"INT64,&n,&m,&md);
	for (int i=0;i<m;i++){
		scanf(INT64 INT64 INT64 INT64,&l,&r,&u,&v);
		printf("%d\n",(int)calc(1,n,1,1));
	}

	return 0;
}