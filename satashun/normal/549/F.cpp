#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <cctype>
#include <queue>
#include <map>

using namespace std;

#define rep(i,n) for(int i=0;i<(int)n;++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back

typedef pair<int, int> pii;
typedef long long ll;

#define MX 1000010

int k;
ll lcnt[MX], rcnt[MX];

ll count(const vector<int>& vec) {
  if (vec.size() <= 1) return 0;
  
  int n = vec.size();
  
  vector<int> lt(vec.begin(), vec.begin() + n/2);
  vector<int> rt(vec.begin() + n/2, vec.end());

  ll ret = count(lt) + count(rt);

  int l = n / 2 - 1, r = n / 2;
  int ma = 0;

  int lmax = 0, rmax = 0;
  ll lsum = 0, rsum = 0;
  
  vector<int> lu, ru;
  
  while (l >= 0 || r < n) {
    if (l >= 0 && (r >= n || max(lmax, vec[l]) <= max(rmax, vec[r]))) {
      lmax = max(lmax, vec[l]);
      lsum = (lsum + vec[l]) % k;
      ++lcnt[lsum];
      lu.pb(lsum);
      
      int zan = (-lsum + lmax + k) % k;
      ret += rcnt[zan];
      --l;
      
    } else {
      rmax = max(rmax, vec[r]);
      rsum = (rsum + vec[r]) % k;
      ++rcnt[rsum];
      ru.pb(rsum);
      
      int zan = (-rsum + rmax + k) % k;
      ret += lcnt[zan];
      ++r;
    }
  }
  
  rep(i, lu.size()) --lcnt[lu[i]];
  rep(i, ru.size()) --rcnt[ru[i]];
  
  return ret;
}

int n;

int main() {
  scanf("%d %d", &n, &k);
  vector<int> a(n);
  rep(i, n) scanf("%d", &a[i]);
  cout << count(a) << endl;
  return 0;
}