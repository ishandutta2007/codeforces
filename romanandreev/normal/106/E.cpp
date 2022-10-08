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
typedef double ld;
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

#define TASK ""
int x[10000];
int y[10000];
int z[10000];
ld xx[100];
int n;       
inline ld sqr(ld x){
        return x*x;
}
ld trn(int k){
        if(k==3){
                ld ans=0;
                for (int i=0;i<n;i++){
                        ans=max(ans,sqr(xx[0]-x[i])+sqr(xx[1]-y[i])+sqr(xx[2]-z[i]));
                }
                return ans;
        }
        ld l,r,m1,m2,f1,f2;
        l=-1e4;
        r=1e4;
        for (int i=0;i<60;i++){
                m1=(l*2+r)/3;
                m2=(l+r*2)/3;
                xx[k]=m1;
                f1=trn(k+1);
                xx[k]=m2;
                f2=trn(k+1);
                if (f1<f2){
                        r=m2;
                } else 
                        l=m1;
        }
        return f1;
}
int main(){
        #ifdef home
        assert(freopen(TASK".out","wt",stdout));
        assert(freopen(TASK".in","rt",stdin));
        #endif
        scanf("%d",&n);
        for (int i=0;i<n;i++){
                scanf("%d%d%d",&x[i],&y[i],&z[i]);
        }
        trn(0);
        printf("%.18lf %.18lf %.18lf\n",(double)xx[0],(double)xx[1],(double)xx[2]);
        return 0;
}