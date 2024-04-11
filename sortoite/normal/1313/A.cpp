#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;
using DO = double;
using LL = long long;
using VI = vector<int>;
using pii = pair<int, int>;
const int mod = 1e9+7;
int power(int a, int b, int c=mod) {
  int ans=1;
  for(; b; b>>=1, a=(LL)a*a%c) {
    if(b&1) ans=(LL)ans*a%c;
  }
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("A.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  while(T--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int ans=0;
    if(a) ans++, a--;
    if(b) ans++, b--;
    if(c) ans++, c--;
    if(a>b) swap(a, b);
    if(b>c) swap(b, c);
    if(a>b) swap(a, b);
    if(b>c) swap(b, c);
    if(a && c) a--, c--, ans++;
    if(b && c) c--, b--, ans++;
    if(a && b) a--, b--, ans++;
    if(a && b && c) ans++;
    printf("%d\n", ans);
  }
  return 0;
}