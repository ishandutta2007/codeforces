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
const int dx[4]  = {1, 0, -1, 0};
const int dy[4]  = {0, 1, 0, -1};
const char dc[4] = {'R', 'U', 'L', 'D'};
int n;
char s[1000000][6];
int tx, ty;
int main(){
	#ifdef home
	assert(freopen(problem_name".out","wt",stdout));
	assert(freopen(problem_name".in","rt",stdin));
	#endif
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s\n", s[i]);
	}	        
	int tx = 1;
	int ty = 1;
	for (int i = n - 1; i >= 0; i--) {
		if (strlen(s[i]) == 4) {
			tx++, ty++;
		} else {
			if (s[i][0] == 'U' && s[i][1] == 'L') {
				tx++;
			} else
			if (s[i][0] == 'D' && s[i][1] == 'R') {
				tx++;
			} else {
				ty++;
			}
		}
	}
	cout<<(ll)tx * ty<<endl;
	return 0;
}