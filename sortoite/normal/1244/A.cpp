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


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  
  int a, b, c, d, k, e,f;
  int T;
  scanf("%d", &T);
  while(T--) {
  	cin>>a>>b>>c>>d>>k;
		e=f=0;
  	k-=(e=(a+c-1)/c);
  	k-=(f=(b+d-1)/d);
  	if(k<0) {
  		puts("-1");
  		continue;
  	}
  	e+=k;
  	cout<<e<<' '<<f<<endl;
  }
  
  return 0;
}