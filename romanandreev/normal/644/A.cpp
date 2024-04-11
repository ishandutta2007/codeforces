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
  int n, a, b;
  cin >> n >> a >> b;
  int o = a * b / 2;
  int e = a * b - o;
  int n1 = n / 2;
  int n2 = n - n1;
  if (!(o >= n1 && e >= n2)) {
    printf("-1\n");
    return 0;
  }
  int c1 = 1;
  int c2 = 2;
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      if ((i + j) % 2 == 0) {
        if (n2 > 0) {
          n2--;
          printf("%d ", c1);
          c1 += 2;
        } else {
          printf("%d ", 0);
        }
      } else {
        if (n1 > 0) {
          n1--;
          printf("%d ", c2);
          c2 += 2;
        } else {
          printf("%d ", 0);
        }
      }
    }
    printf("\n");
  }
  return 0;
}