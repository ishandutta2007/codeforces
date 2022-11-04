#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back

using namespace std;
template<typename T, typename U> inline void smin(T &a, const U &b) {if (a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if (a<b) a=b;}

inline int power(int a, int b, int m, int ans=1) {
  for(; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
  return ans;
}

char s[1111];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  
  int T;
  cin>>T;
  while(T--) {
  	int n;
  	scanf("%d %s", &n, s+1);
  	int mn=n+1, mx=0;
  	for(int i=1; i<=n; i++) if(s[i] == '1') {
  		mn=min(mn, i);
  		mx=max(mx, i);
  	}
  	if(mn == n+1) {
  		printf("%d\n", n);
  		continue;
  	}
  	int ans=n+1;
  	smax(ans, mx*2);
  	smax(ans, (n-mn+1)*2);
  	cout<<ans<<endl;
  }
  return 0;
}