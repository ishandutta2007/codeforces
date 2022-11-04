#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;
typedef double DO;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> pii;

const int inf=0x3f3f3f3f, mod=1000000007;
const LL INF=0x3f3f3f3f3f3f3f3fLL;
const DO pi=acosl(-1.), eps=1e-9;

int power(int a, int b, int m=mod, int ans=1) {
  for(; b; b>>=1, a=(LL)a*a%m) if (b&1) ans=(LL)ans*a%m;
  return ans;
}

const int NN = 2e5+10;
char s[NN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  
  int T;
  cin>>T;
  VI v;
  while(T--) {
    scanf("%s", s);
    int n=strlen(s);
    v.clear();
    for(int i=0; i<n; ) {
      if(i+4<n && s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o' && s[i+3] == 'n' && s[i+4] == 'e') {
        v.pb(i+2);
        i+=5;
      }else if(i+2<n && s[i] == 'o' && s[i+1] == 'n' && s[i+2] == 'e') {
        v.pb(i+1);
        i+=3;
      }else if(i+2<n && s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o') {
        v.pb(i+1);
        i+=3;
      }else i++;
    }
    printf("%d\n", v.size());
    for(auto r:v) printf("%d ", r+1);
    puts("");
  }
  
  return 0;
}