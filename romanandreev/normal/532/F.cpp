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
#define hash hash_fdfsdfsdgfs

#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
#define problem_name "a"
const int P1[] = {17239, 23917};
int MD[2];

struct hash {
  int x, y;
  hash() {
  }
  hash(int x1, int y1) : x(x1), y(y1) {
  }
};
bool prime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
hash operator + (hash a, hash b) {
  return hash((a.x + b.x) % MD[0], (a.y + b.y) % MD[1]);
}
hash operator - (hash a, hash b) {
  return hash((a.x - b.x + MD[0]) % MD[0], (a.y - b.y + MD[1]) % MD[1]);
}
hash operator * (hash a, hash b) {
  return hash((int)(((ll)a.x * b.x) % MD[0]), (int)(((ll)a.y * b.y) % MD[1]));
}
bool operator == (hash a, hash b) {
  return a.x == b.x && a.y == b.y;
}
bool operator != (hash a, hash b) {
  return a.x != b.x || a.y != b.y;
}

bool operator < (const hash& a, const hash& b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}
hash h[2][26][(int)2e5 + 10];
hash stp[(int)2e5 + 10];
int n[2];
char s[2][1000000];
vector<int> g[100];
hash f1[100];
hash f2[100];

int num1[100];
int num2[100];
int pr[100];

int main(){
//  #ifndef NOFILES
//  assert(freopen(problem_name".out","wt",stdout));
//  assert(freopen(problem_name".in","rt",stdin));
//  #endif
  vector<int> P;
  for (int i = 1e9 + 20; sz(P) < 10; i++) {
    if (prime(i)) {
      P.pb(i);
    }
  }
  srand((int)time(0));
  int x = rand() % sz(P);
  MD[0] = P[x];
  MD[1] = P[(x + 1) % sz(P)];
  
  scanf("%d %d", &n[0], &n[1]);
  scanf("%s", s[0]);
  scanf("%s", s[1]);
  stp[0] = hash(1, 1);
  for (int i = 1; i <= max(n[0], n[1]); i++) {
    stp[i] = stp[i - 1] * hash(P1[0], P1[1]);
  }
  for (int i = 0; i < 2; i++) {
    for (int c = 0; c < 26; c++) {
      h[i][c][n[i]] = hash(0, 0);    
      for (int j = n[i] - 1; j >= 0; j--) {
        h[i][c][j] = h[i][c][j + 1] * stp[1] + hash(s[i][j] - 'a' == c, s[i][j] - 'a' == c);
      }
    }
  }
  vector<int> ans;
  for (int i = 0; i < n[0] - n[1] + 1; i++) {
    vector<hash> ls;
    int c1 = 0;
    int c2 = 0;
    for (int j = 0; j < 26; j++) {
      f1[j] = h[0][j][i] - h[0][j][i + n[1]] * stp[n[1]];
      f2[j] = h[1][j][0];
      if (f1[j] != hash(0, 0)) {
        ls.pb(f1[j]);
        c1++;
      }
      if (f2[j] != hash(0, 0)) {
        ls.pb(f2[j]);
        c2++;
      }      
    }
    if (c1 != c2) continue;
    image(ls);
    for (int j = 0; j < 52; j++) {
      g[j].clear();
      pr[j] = -1;
    }    
    for (int j = 0; j < 26; j++) {
      if (f1[j] != hash(0, 0)) {    
        num1[j] = (int)(lower_bound(all(ls), f1[j]) - ls.begin());
        g[num1[j]].pb(j);
      }
      if (f2[j] != hash(0, 0)) {
        num2[j] = (int)(lower_bound(all(ls), f2[j]) - ls.begin());      
        g[num2[j]].pb(j);
      }
    }    
    for (int j = 0; j < 52; j++) {
      if (sz(g[j]) == 0) continue;
      if (sz(g[j]) != 2) {
        goto en;
      }
      if (pr[g[j][0]] != -1 && pr[g[j][0]] != g[j][1]) {
        goto en;
      }
      pr[g[j][0]] = g[j][1];
      if (pr[g[j][1]] != -1 && pr[g[j][1]] != g[j][0]) {
        goto en;
      }
      pr[g[j][1]] = g[j][0];
    }
    for (int j = 0; j < 26; j++) if (pr[j] != -1) {      
      if (pr[pr[j]] != j) goto en;
    }
    ans.pb(i + 1);
    en:;
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d%c", ans[i], " \n"[i + 1 == sz(ans)]);
  }
  return 0;
}