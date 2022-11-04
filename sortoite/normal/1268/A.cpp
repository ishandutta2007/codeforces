#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back

using namespace std;
template<typename T, typename U> inline void smin(T &a, const U &b) {if (a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if (a<b) a=b;}

using DO = double;
using LL = long long;
using VI = vector<int>;
using pii = pair<int, int>;

const int mod=1000000007;
const int inf=0x3f3f3f3f;
const DO pi = acosl(-1.);
const DO eps = 1e-9;

int power(int a, LL b, int m=mod, int ans=1) {
  for(; b; b>>=1, a=(LL)a*a%m) if (b&1) ans=(LL)ans*a%m;
  return ans;
}

const int N = 2e5+10;

char s[N], t[N];
int n, k;


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  
  scanf("%d %d %s", &n, &k, s);
  
  int ok=1;
  for(int i=0; i<n; i++) {
    if(i+k<n && s[i] != s[i+k]) ok=0;
  }
  if(ok) {
    cout<<n<<endl;
    printf("%s\n", s);
    return 0;
  }
  
  for(int i=0; i<k; i++) t[i]=s[i];
  for(int i=k; i<n; i++) t[i]=t[i-k];
  ok=1;
  for(int i=0; i<n; i++) if(t[i] != s[i]) {
    if(t[i]<s[i]) ok=0;
    break;
  }
  if(ok) {
    cout<<n<<endl;
    cout<<t<<endl;
    return 0;
  }
  
  cout<<n<<endl;
  s[k-1]++;
  for(int i=k-2; i>=0; i--) {
    if(s[i+1] == '9'+1) {
      s[i+1]='0';
      s[i]++;
    }else break;
  }
  
  for(int i=0; i<n; i++) {
    putchar(s[i%k]);
  }
  puts("");
  
  return 0;
}