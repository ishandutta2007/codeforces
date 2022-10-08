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
#define x first
#define y second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
#define problem_name "a"
const int md = 1e9 + 7;
int n;
int a[1002];
int dp[1002];

int main(){
    #ifdef home
    assert(freopen(problem_name".out","wt",stdout));
    assert(freopen(problem_name".in","rt",stdin));
    #endif
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        a[i]--;
    }
    dp[0] = 2;
    for (int i = 1; i < n; i++) {
        dp[i] = 2;
        for (int j = a[i]; j < i; j++) {
            dp[i] = (dp[i] + dp[j]) % md;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = (sum + dp[i]) % md;
    }
    cout<<sum<<endl;
    return 0;
}