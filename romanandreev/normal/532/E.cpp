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
int n;
char s1[1000000];
char s2[1000000];

int main(){
  scanf("%d", &n);
  scanf("%s", s1);
  scanf("%s", s2);
  int p1 = n + 1;
  int p2 = -1;
  for (int i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      p1 = min(p1, i);
      p2 = max(p2, i);
    }
  }  
  set<pair<char, char> > S;
  bool can1 = true;
  for (int i = p1; i < p2; i++) {
    if (s1[i] != s2[i + 1]) {
      can1 = false;
    }
  }
  
  if (can1) {
    S.insert(mp(s2[p1], s1[p2]));
  }
  bool can2 = true;
  for (int i = p1; i < p2; i++) {
    if (s2[i] != s1[i + 1]) {
      can2 = false;
    }
  }
  
  if (can2) {
    S.insert(mp(s1[p1], s2[p2]));
  }
  printf("%d\n", sz(S));
  return 0;
}