#include <bits/stdc++.h>
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
int n, k;
map<pair<int, int>, int> M;
int calc(int i, int j) {
  if (i + j == k) {
    return j % 2;
  }
  if (M.find(mp(i, j)) != M.end()) {
    return M[mp(i, j)];
  }
  if ((i + j) % 2 == n % 2) {
    int res = 0;
    if (i > 0 && calc(i - 1, j) == 1) {
      res = 1;
    }
    if (j > 0 && calc(i, j - 1) == 1) {
      res = 1;
    }
    return M[mp(i, j)] = res;
  } else {
    int res = 1;
    if (i > 0 && calc(i - 1, j) == 0) {
      res = 0;
    }
    if (j > 0 && calc(i, j - 1) == 0) {
      res = 0;
    }
    return M[mp(i, j)] = res;
  }
} 
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  scanf("%d %d", &n, &k);
  int a0 = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (x % 2 == 0) {
      a0++;
    }
  }
  int a1 = n - a0;
  while (a0 >= 4 && a1 >= 4 && a0 + a1 >= k + 6) {
    a0 -= 2;
    a1 -= 2;
  }
  int res = calc(a0, a1);
  if (res == 0) {
    cout << "Daenerys" << endl;
  } else {
    cout << "Stannis" << endl;
  }
  return 0;
}