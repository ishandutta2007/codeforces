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

int n,ff;
char s[3000][3000];
int a[3000][3000];
int d1[3000][3000];
int d2[3000][3000];


int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%s",s[i]);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++){
			if (s[i][j]=='1')
				a[i][j]=1;
			else
				a[i][j]=0;
		}

	ll ans=0;
	for (int i=n-1;i>=0;i--)
		for (int j=0;j<i;j++){
			ff=a[i][j]^d1[i][j]^d2[i][j];
			ans+=ff;			
			d1[i][j]^=ff;
			d2[i][j]^=ff;
			d1[i][j+1]^=d1[i][j];
			d2[i-1][j]^=d2[i][j];
		}
	for (int i=0;i<n;i++)
		for (int j=n-1;j>i;j--){
			ff=a[i][j]^d1[i][j]^d2[i][j];
			ans+=ff;			
			d1[i][j]^=ff;
			d2[i][j]^=ff;
			d1[i][j-1]^=d1[i][j];
			d2[i+1][j]^=d2[i][j];
		}
	for (int i=0;i<n;i++){
		ans+=a[i][i]^d1[i][i]^d2[i][i];
	}
	cout<<ans<<endl;
	return 0;
}