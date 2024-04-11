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

void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> a(n - k + 1, 0);
  vector<int> b(n);
  for (int i = 0; i < n - k + 1; i++) {
    char s[5];
    scanf("%s", s);
    if (s[0] == 'Y') {
      a[i] = 1;
    }
  }
  for (int i = 0; i < k - 1; i++) {
    b[i] = i + 1;
  }
  int CNT = k;
  for (int j = k - 1; j < n; j++) {
    if (a[j - k + 1] == 1) {
      b[j] = CNT++;
    } else {
      b[j] = b[j - k + 1];
    }
  }
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    while (b[i] > 0) {
      printf("%c", (cnt == 0 ? 'A' : 'a') + b[i] % 26);
      cnt++;      
      b[i] /= 26;
    }
    printf(" ");
  }
}

int main(){
  #ifdef home
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  #endif
  solve();
  return 0;
}