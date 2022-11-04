#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define sq(x) ((x)*(x))
using namespace std;
typedef double DO;
typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef pair<pii, int> pi3;

const int inf=0x3f3f3f3f,mod=1000000007;
const INT INF=0x3f3f3f3f3f3f3f3fLL;
const DO pi=acosl(-1.),eps=1e-9;

inline int power(int a, int b, int m=mod, int ans=1) {
  for(; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  
  int n, d, e;
  cin>>n>>d>>e;
  e*=5;
  int ans=0x3f3f3f3f;
  for(int i=0; i<d; i++) {
    if(i*e<=n) ans=min(ans, (n-i*e)%d);
  }
  cout<<ans<<endl;
  return 0;
}