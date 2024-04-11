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

int main(){
  #ifdef home
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  #endif              
  int h, m, a;
  scanf("%d:%d %d", &h, &m, &a);
  int t = (h * 60 + m + a) % (24 * 60);
  printf("%02d:%02d\n", t / 60, t % 60);
  return 0;
}