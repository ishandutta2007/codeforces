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

ll f[100];
ll n;
int T;
int r[100];
int ans;
int dp[100][2][2];

int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	f[1]=1;
	f[2]=2;
	int N=87;
	for (int i=3;i<=N;i++){
		f[i]=f[i-1]+f[i-2];
	}
	scanf("%d",&T);
	while (T-->0){
		scanf(INT64,&n);
		for (int i=N;i>=1;i--){
			if (n>=f[i]){
				n-=f[i];
				r[i]=1;
			} else 
				r[i]=0;
		}
		memset(dp,0,sizeof(dp));
		dp[N+3][0][0]=1;
		for (int i=N+2;i>=1;i--){
			if (r[i]==0){
				for (int r1=0;r1<2;r1++)
					for (int r2=0;r2<2;r2++)
						dp[i][0][r1]+=dp[i+1][r1][r2];
				dp[i][1][1]+=dp[i+1][0][1];
			} else {
				for (int r1=0;r1<2;r1++)
					dp[i][0][r1]+=dp[i+1][r1][0];
				dp[i][1][1]+=dp[i+1][0][0];
				dp[i][1][1]+=dp[i+1][0][1];
			}
		 }
		 ans=dp[1][0][0];
		printf("%d\n",ans);	
	}
//	cerr<<clock()*1.0/CLOCKS_PER_SEC<<endl;
	return 0;
}