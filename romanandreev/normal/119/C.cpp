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

int n,m,K;
int k[1000];
int p[1000];
ll a[1000];
ll b[1000];
int c[1000];
ll dp[200][200][200];
int bc1[200][200][200];
int bc2[200][200][200];

void bct(int x,int y,int z){
	if (y==0) return;
	bct(bc1[x][y][z],y-1,bc2[x][y][z]);
	cout<<p[x]+1<<" "<<a[p[x]]+z<<endl;
}
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	cin>>n>>m>>K;
	for (int i=0;i<m;i++){
		cin>>a[i]>>b[i]>>c[i];
		k[i]=b[i]-a[i]+1;
		p[i]=i;
	}
	for (int i=0;i<m;i++)
		for (int j=i+1;j<m;j++)if (c[p[i]]>c[p[j]]){
			swap(p[i],p[j]);
		}
	for (int i=0;i<=m;i++)
		for (int cc=0;cc<=n;cc++)
			for (int j=0;j<=100;j++)
				dp[i][cc][j]=-1;
	for (int j=0;j<m;j++)
		for (int i=0;i<k[p[j]];i++){
			dp[j][1][i]=i+a[p[j]];
		}
	for (int cc=1;cc<=n;cc++){
		for (int j=0;j<m;j++){
			for (int l=0;l<k[p[j]];l++)if (dp[j][cc-1][l]!=-1){
				for (int i=j+1;i<m;i++)if (c[p[j]]<c[p[i]]){
					if (a[p[j]]+l+K>=a[p[i]] && a[p[j]]+l+K<=b[p[i]] && dp[i][cc][a[p[j]]+l+K-a[p[i]]]<dp[j][cc-1][l]+a[p[j]]+l+K){
						dp[i][cc][a[p[j]]+l+K-a[p[i]]]=dp[j][cc-1][l]+a[p[j]]+l+K;
						bc1[i][cc][a[p[j]]+l+K-a[p[i]]]=j;
						bc2[i][cc][a[p[j]]+l+K-a[p[i]]]=l;
					}
					if ((a[p[j]]+l)*K>=a[p[i]] && (a[p[j]]+l)*K<=b[p[i]] && dp[i][cc][(a[p[j]]+l)*K-a[p[i]]]<dp[j][cc-1][l]+(a[p[j]]+l)*K){
						dp[i][cc][(a[p[j]]+l)*K-a[p[i]]]=dp[j][cc-1][l]+(a[p[j]]+l)*K;
						bc1[i][cc][(a[p[j]]+l)*K-a[p[i]]]=j;
						bc2[i][cc][(a[p[j]]+l)*K-a[p[i]]]=l;
					}
				}
			}
		}
	}
	ll mx=-1;
	int mx1=0,mx2=0;
	for (int i=0;i<m;i++)
		for (int j=0;j<k[p[i]];j++){
			if (dp[i][n][j]>mx){
				mx=dp[i][n][j];
				mx1=i;
				mx2=j;
			}
		}
	if (mx==-1){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	bct(mx1,n,mx2);
	return 0;
}