#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define image(a) {sort(all(a)), a.resize(unique(all(a)) - a.begin());}
int n;
const int maxn = 210;
char s[maxn];
int cnt[2 * maxn][2 * maxn];
int main(){
  #ifdef home
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  #endif              
  scanf("%d", &n);
  scanf("%s", s);
  int x = maxn;
  int y = maxn;
  cnt[x][y]++;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    switch (s[i]) {
      case 'U': y++; break;
      case 'D': y--; break;
      case 'L': x--; break;      
      case 'R': x++; break;      
    }
    ans += cnt[x][y];
    cnt[x][y]++;
  }
  cout << ans << endl;
  return 0;
}