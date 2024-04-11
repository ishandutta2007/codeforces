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

typedef long long int64;
typedef long long ll;
typedef long double d64;

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
int n,m;
const int md=1000003;
vector<int> a[1000000];
int cnt,aa,ans;
char s[1000000];
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++){
		a[i].reserve(m);
		for (int j=0;j<m;j++){
			a[i].pb(0);
		}
	}
	cnt=0;
	for (int i=0;i<n;i++){
		scanf("%s",s);
		for (int j=0;j<m;j++){
			if (s[j]!='.'){
				a[i][j]=s[j]-'0';
				cnt++;
			}
		}	
	}	
	ans=0;
	for (int i=0;i<n;i++){
		bool bl1=true;
		bool bl2=true;
		for (int j=0;j<m;j++){
			if (a[i][j]==1 || a[i][j]==2){
				if (j%2==0){
					bl2=false;
				} else
					bl1=false;
			}
			if (a[i][j]==3 || a[i][j]==4){
				if (j%2==0){
					bl1=false;
				} else
					bl2=false;
			}
		}
		if (bl1 && bl2){
			ans++;
		}
		if (!bl1 && !bl2){
			cout<<0<<endl;
			return 0;
		}
	}
	for (int i=0;i<m;i++){
		bool bl1=true;
		bool bl2=true;
		for (int j=0;j<n;j++){
			if (a[j][i]==1 || a[j][i]==4){
				if (j%2==0){
					bl2=false;
				} else
					bl1=false;
			}
			if (a[j][i]==3 || a[j][i]==2){
				if (j%2==0){
					bl1=false;
				} else
					bl2=false;
			}
		}
		if (bl1 && bl2){
			ans++;
		}
		if (!bl1 && !bl2){
			cout<<0<<endl;
			return 0;
		}
	}
	aa=1;
	for (int i=0;i<ans;i++){
		aa=(aa*2)%md;
	}
	cout<<aa<<endl;
	return 0;
}