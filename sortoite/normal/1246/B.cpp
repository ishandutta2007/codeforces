#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define pb push_back
typedef double DO;
typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;
using VP = vector<pii>;

const int NN = 1e5+1;

int flag[NN];
int a[NN];
VP b[NN];
map<VP, int> mp;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  for(int i=2; i<NN; i++) if(flag[i] == 0) {
    flag[i] = i;
    if((INT)i*i>NN) continue;
    for(int j=i*i; j<NN; j+=i) if(flag[j] == 0) flag[j]=i;
  }
  
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i=1; i<=n; i++) {
    scanf("%d", &a[i]);
    int m=a[i];
    b[i].pb({0, 0});
    while(m>1) {
      int t=flag[m], r=0;
      while(m%t == 0) m/=t, r++;
      r%=k;
      if(r) b[i].pb({t, r});
    }
    sort(b[i].begin(), b[i].end());
    mp[b[i]]++;
  }
  INT ans=0;
  VP tmp;
  for(int i=1; i<=n; i++) {
    tmp.clear();
    tmp.pb({0, 0});
    for(int j=1; j<b[i].size(); j++) {
      tmp.pb({b[i][j].x, k-b[i][j].y});
    }
    if(mp.count(tmp)) {
      ans+=mp[tmp]-(b[i] == tmp);
    }
  }
  cout<<ans/2<<endl;
  return 0;
}