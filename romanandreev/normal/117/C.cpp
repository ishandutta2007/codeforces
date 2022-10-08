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
char a[5010][5010];
void calc(vi v){
	int k=sz(v);
	if (k<3) return;
	vi v1,v2;
	for (int l=1;l<k;l++)if (a[v[0]][v[l]]=='1'){
		v2.pb(v[l]);
	} else 
		v1.pb(v[l]);
	for (int i=0;i<sz(v2);i++)
		for (int j=0;j<sz(v1);j++){
			if (a[v2[i]][v1[j]]=='1'){
				cout<<v[0]+1<<" "<<v2[i]+1<<" "<<v1[j]+1<<endl;
				exit(0);
			}
		}
	calc(v1);
	calc(v2);
	return;
}
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	int n;
	vi v;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	for (int i=0;i<n;i++){
		v.pb(i);
	}
	calc(v);
	printf("-1\n");
	return 0;
}