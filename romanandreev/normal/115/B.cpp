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

int n,m,ks,ans,tkx,tky,np;
char a[1000][1000];
int b[1000][1000];

int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	scanf("%d%d",&n,&m);
	ks=0;
	for (int i=0;i<n;i++){
		scanf("%s",a[i]);
		for (int j=0;j<m;j++)if (a[i][j]=='W'){
			ks++;
			b[i][j]=1;
		}
	}
	ans=0;
	tkx=0;
	tky=0;
	np=1;
	while (ks>0){
		bool bl=false;
		for (int i=tky;i>=0 && i<m;i+=np){
			if (b[tkx][i]==1){
				bl=true;
				b[tkx][i]=0;
				ks--;
				ans+=abs(tky-i);
				tky=i;
				break;
			}
		}
		if (bl) continue;
		int ff=tky;
		for (int i=tky+np;i>=0 && i<m;i+=np){
			if (b[tkx+1][i]==1){
				ff=i;
			}
		}
		ans+=abs(tky-ff)+1;
		tky=ff;
		tkx++;
		np=-np;
	}	
	cout<<ans<<endl;
	return 0;
}