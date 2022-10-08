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
const int maxn=2000000;
char s1[maxn];
char s2[maxn];
char s3[2*maxn];
int p[2*maxn];


ll h1[maxn];
ll h2[maxn];
ll h1r[maxn];
ll h2r[maxn];
ll stp[maxn];
int f1[maxn];
int f2[maxn];
int len[maxn];


int get1(int x,int l){
	return h1[x]-h1[x+l]*stp[l];
}
int get2(int x,int l){
	return h2[x]-h2[x+l]*stp[l];
}
int get1r(int x,int l){
	return h1r[x]-h1r[x+l]*stp[l];
}
int get2r(int x,int l){
	return h2r[x]-h2r[x+l]*stp[l];
}

int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	gets(s1);
	gets(s2);
	int n=strlen(s1);
	if (strlen(s1)!=strlen(s2)){
		printf("-1 -1\n");
		return 0;
	}
	s3[n]=1;
	for (int i=0;i<n;i++){
		s3[i]=s1[n-1-i];
		s3[i+n+1]=s2[i];
	}
	int k=0;
	for (int i=1; i<=2*n; i++) {
		while (k > 0 && s3[i] != s3[k])
			k = p[k-1];
		if (s3[i] == s3[k]) k++;
		p[i] = k;
	}
	stp[0]=1;
	for (int i=1;i<=n;i++){
		stp[i]=stp[i-1]*239;
	}
	h1[n]=0;
	for (int i=n-1;i>=0;i--){
		h1[i]=h1[i+1]*239+s1[i];
	}
	h2[n]=0;
	for (int i=n-1;i>=0;i--){
		h2[i]=h2[i+1]*239+s2[i];
	}
	h1r[n]=0;
	for (int i=n-1;i>=0;i--){
		h1r[i]=h1r[i+1]*239+s1[n-i-1];
	}
	h2r[n]=0;
	for (int i=n-1;i>=0;i--){
		h2r[i]=h2r[i+1]*239+s2[n-i-1];
	}
	int l,r,m;
	int ans1,ans2;
	ans1=-1;
	ans2=1e9;
	for (int i=1;i<=n;i++){
		if (get1(0,i)==get2r(0,i)){
			l=0;
			r=n-i;
			while (l<r){
				m=(l+r+1)/2;
				if (get1(i,m)==get2(0,m)){
					l=m;
				} else r=m-1;
			}
		    if (p[2*n-i]>0 && p[2*n-i]+l>=n-i){
		    	if (ans1<i-1 || ((ans1==i)&&(ans2>n-p[2*n-i]))){
		    		ans1=i-1;
		    		ans2=n-p[2*n-i];
		    	}
		    }
		}
	}
	if (ans1==-1){
		printf("-1 -1\n");
		return 0;
	}	
	printf("%d %d\n",ans1,ans2);
	return 0;
}