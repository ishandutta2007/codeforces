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
map<vector<int>, int> M;
void dfs(vector<int> cnt) {
  if (M[cnt] != 0) return;
  M[cnt] = 1;
  for (int i = 0; i < 3; i++) {
    if (cnt[i] >= 2) {
      auto cnt2 = cnt;
      cnt2[i]--;
      dfs(cnt2);
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 3; j++) {
      if (cnt[i] > 0 && cnt[j] > 0) {
        auto cnt2 = cnt;
        cnt2[i]--;
        cnt2[j]--;
        cnt2[0 + 1 + 2 - i - j]++;        
        dfs(cnt2);
      }
    }
  }
}
int main(){
  #ifdef home
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  #endif              
  scanf("%d", &n);
  scanf("%s", s);  
  vector<int> cnt(3, 0);
  for (int i = 0; i < n; i++) {
    switch (s[i]) {
      case 'B': cnt[0]++; break;
      case 'G': cnt[1]++; break;
      case 'R': cnt[2]++; break;
    }
  }
  for (int i = 0; i < 3; i++) {
    cnt[i] = min(cnt[i], 2);
  }
  dfs(cnt);
  if (M[{1, 0, 0}] == 1) {
    cout << "B";
  }
  if (M[{0, 1, 0}] == 1) {
    cout << "G";
  }
  if (M[{0, 0, 1}] == 1) {
    cout << "R";
  }
  return 0;
}