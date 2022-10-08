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
ll t1,t2,x1,x2,t0,ans1,ans2,z1,z2,y20;
inline void trr(const ll& y1,const ll& y2){
	if (y1==0 && y2==0) return;
	if (ans1==-1){
		if ((y1*t1+y2*t2)>=t0*(y1+y2)){
			ans1=y1;
			ans2=y2;
		}
		return;
	}
	z1=(ans1*t1+ans2*t2)*(y1+y2)-t0*(y1+y2)*(ans1+ans2);
	z2=(y1*t1+y2*t2)*(ans1+ans2)-t0*(y1+y2)*(ans1+ans2);            
	if ((z1>=0 && z2>=0)&&(z1>z2 || ((z1==z2)&&(y1+y2>ans1+ans2)))){
		ans1=y1;
		ans2=y2;
	}
}        	
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif
	cin>>t1>>t2>>x1>>x2>>t0; 
	ans1=-1;
	ans2=-1;
	trr(0,x2);
	trr(x1,0);
	trr(x1,x2);
	for (ll y1=0;y1<=x1;y1++)if (t2!=t0){
		y20=((t0-t1)*y1)/(t2-t0);
		//for (ll y2=0;y2<=x2;y2++){
//		cerr<<y1<<" "<<y20<<endl;
		for (ll y2=max(0LL,y20-2);y2<=min(x2,y20+2);y2++){
			trr(y1,y2);
		}
	}
	cout<<ans1<<" "<<ans2<<endl;
	
	return 0;
}