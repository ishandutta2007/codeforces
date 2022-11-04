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

const int N = 2e5+100;

LL B[N];
int C[N];

void updateb(int u, int d) {
  for(; u<N; u+=u&-u) B[u]+=d;
}
void updatec(int u) {
  for(; u<N; u+=u&-u) C[u]++;
}

LL calcb(int u) {
  LL ans=0;
  for(; u>0; u-=u&-u) ans+=B[u];
  return ans;
}

int calcc(int u) {
  int ans=0;
  for(; u>0; u-=u&-u) ans+=C[u];
  return ans;
}

int p[N], a[N];
LL c(int a) {
  return (LL)a*(a+1)/2;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  
  int n;
  cin>>n;
  for(int i=1; i<=n; i++) {
    scanf("%d", p+i);
    a[p[i]]=i;
  }
  
  LL inv=0, tot=0;
  for(int i=1; i<=n; i++) {
    inv+=i-1-calcc(a[i]);
    updatec(a[i]);
    updateb(a[i], a[i]);
    tot+=a[i];
    int st=0, ed=n;
    while(st+1<ed) {
      int md=st+ed>>1;
      if(calcc(md) < (i+1)/2) st=md;
      else ed=md;
    }
    st++;
//    cerr<<i<<' '<<st<<' '<<inv<<endl;
//    for(int i=1; i<=n; i++) {
//      cerr<<calcb(i)-calcb(i-1)<<' ';
//    }
//    cerr<<endl;
//    cerr<<inv+(c(st)-c(st-(i+1)/2)) + tot - 2*calcb(st) - (c(st+(i/2))-c(st))<<endl;
    printf("%I64d ", inv+(c(st)-c(st-(i+1)/2)) + tot - 2*calcb(st) - (c(st+(i/2))-c(st)));
  }
  
  return 0;
}