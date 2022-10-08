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

char s[2000000];
ll h[2000000];
ll stp[2000000];

int ff;
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	scanf("%s",s);
	int n=strlen(s);
	h[n]=0;
	stp[0]=1;
	for (int i=1;i<=n;i++){
		stp[i]=stp[i-1]*23917;
	}
	for (int i=n-1;i>=0;i--){
		h[i]=h[i+1]*stp[1]+s[i];
	}
	vector<int> v;
	for (int i=0;i<n;i++){
		if (h[0]-h[0+i]*stp[i]==h[n-i]){
			v.pb(i);
		}
	}
	int l,r,m;
	l=0;
	r=sz(v)-1;
	while (l<r){
		m=(l+r+1)/2;
		bool bl=false;
		for (int i=1;i<n-v[m];i++){
			if (h[i]-h[i+v[m]]*stp[v[m]]==h[n-v[m]]){
				ff=i;
				bl=true;
				break;
			}
		}
		if (bl){
			l=m;
		} else 
			r=m-1;
	}
	bool bl=false;
	m=l;
	for (int i=1;i<n-v[m]-1;i++){
		if (h[i]-h[i+v[m]]*stp[v[m]]==h[n-v[m]]){
			ff=i;
			bl=true;
			break;
		}
	}
	if (l==0){
		printf("Just a legend\n");
	} else {
		for (int i=0;i<v[m];i++){
			printf("%c",s[ff+i]);
		}
		printf("\n");
	}
	return 0;
}