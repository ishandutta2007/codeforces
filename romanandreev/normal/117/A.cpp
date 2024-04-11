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
int n,m,s,f,t,t0;
int pos(int t){
	t=t%(2*m-1);
	return m-abs(t-m);
}
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	scanf("%d%d",&n,&m);
	for (int it=0;it<n;it++){
		scanf("%d %d %d",&s,&f,&t0);
		s--;
		f--;
		vi v;
		v.clear();
		v.pb(0);
		v.pb(m-1);
		v.pb(s);
		v.pb(f);
		image(v);
		int k=sz(v);
		for (int i=k-1;i>=0;i--){
			v.pb(v[i]);
		}
		for (int j=0;j<2;j++){
			for (int i=0;i<k;i++){
				v.pb(v[i]);
			}
			for (int i=k-1;i>=0;i--){
				v.pb(v[i]);
			}
		}
		int tkp=0;
		int tkt=0;
		if (m>1){
			tkt=(t0/(2*m-2))*(2*m-2);
			while (1){
				if (v[tkp]==s && tkt>=t0){
					break;
				}
				tkt+=abs(v[tkp]-v[tkp+1]);
				tkp++;
			}
			while (1){
				if (v[tkp]==f){
					break;
				}
				tkt+=abs(v[tkp]-v[tkp+1]);
				tkp++;
			}
		}
		if (s==f) tkt=t0;
		printf("%d\n",tkt);
	}
	return 0;
}