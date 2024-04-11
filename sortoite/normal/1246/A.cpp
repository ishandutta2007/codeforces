#include <bits/stdc++.h>
using namespace std;
#define bptl(x) (__builtin_popcountll(x))
#define x first
#define y second
#define pb push_back
typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

const int mod=1000000007;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  
  INT n, p;
  cin>>n>>p;
  int ans=mod;
  for(int i=1; i<10000; i++) {
    if(n-p*i<0) break;
    if(bptl(n-p*i) <= i && n-p*i>=i) ans=min(ans, i);
  }
  if(ans == mod) ans=-1;
  cout<<ans<<endl;
  return 0;
}