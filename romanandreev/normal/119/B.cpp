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

int n,k,q,mn,mx,sum;
int a[10000];
int ff[100];
int b[200][200];
vi v;
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	cin>>n>>k;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>q;
	mn=100000;
	mx=-100000;
	int cc=0;
	for (int i=0;i<q;i++){
		sum=0;
		for (int j=0;j<n/k;j++){
			cin>>b[i][j];
			b[i][j]--;
			if (j==0 && ff[b[i][j]]==0){
				cc++;
			}
			ff[b[i][j]]=1;
			sum+=a[b[i][j]];
		}
		mn=min(mn,sum);
		mx=max(mx,sum);
	}
	for (int i=0;i<n;i++)if (ff[i]==0){
		v.pb(a[i]);
	}
	sort(all(v));
	if ((cc+1)*n/k<=n && sz(v)>=n/k){
		sum=0;
		for (int i=0;i<n/k;i++){
			sum+=v[i];
		}
		mn=min(mn,sum);
		mx=max(mx,sum);
		reverse(all(v));
		sum=0;
		for (int i=0;i<n/k;i++){
			sum+=v[i];
		}
		mn=min(mn,sum);
		mx=max(mx,sum);
	}
	printf("%.18lf %.18lf\n",mn*1.0/(n/k),mx*1.0/(n/k));
	return 0;
}