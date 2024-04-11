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

int main(){
    #ifdef home
    assert(freopen(problem_name".out","wt",stdout));
    assert(freopen(problem_name".in","rt",stdin));
    #endif
    int a, b;
    cin>>a>>b;
    for (int x1 = 1; x1 < a; x1++) {
        int y1 = sqrt(a * a - x1 * x1);
        for (int ff = max(1, y1 - 1); ff <= min(a - 1, y1 + 1); ff++) {
            if (ff * ff + x1 * x1 == a * a) {
                if ((y1 * b) % a == 0 && (x1 * b) % a == 0) {
                    int vx = -y1 * b / a;
                    int vy = x1 * b / a;
                    int x2 = x1 + vx;
                    int y2 = y1 + vy;
                    if (x2 != 0 && y2 != 0) {
                        cout<<"YES"<<endl;
                        cout<<0<<" "<<0<<endl;
                        cout<<x1<<" "<<y1<<endl;
                        cout<<x2<<" "<<y2<<endl;
                        return 0;
                    }
                    x2 = x1 - vx;
                    y2 = y1 - vy;
                    if (x2 != 0 && y2 != 0) {
                        cout<<"YES"<<endl;
                        cout<<0<<" "<<0<<endl;
                        cout<<x1<<" "<<y1<<endl;
                        cout<<x2<<" "<<y2<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}