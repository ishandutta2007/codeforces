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

const int NN =1e5+10;

int B[NN];

void add(int u) {
	for(; u>0; u-=u&-u) B[u]++;
}

int calc(int u) {
	int ans=0;
	for(; u<NN; u+=u&-u) ans+=B[u];
	return ans;
}

int a[NN], b[NN], id[NN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  int n;
  scanf("%d", &n);
  for(int i=1; i<=n; i++) scanf("%d", a+i);
  for(int i=1; i<=n; i++) scanf("%d", b+i), id[b[i]]=i;
  long long ans=0;
  for(int i=1; i<=n; i++) {
  	if(calc(id[a[i]])>0) {
  		ans++;
  	}
  	add(id[a[i]]);
  }
  cout<<ans<<endl;
  return 0;
}