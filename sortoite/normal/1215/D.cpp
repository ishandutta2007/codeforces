#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
template<typename T, typename U> inline void smin(T &a, const U &b) {if (a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if (a<b) a=b;}

inline int power(int a, int b, int m, int ans=1) {
  for(; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
  return ans;
}

const int NN = 2e5+10;
char s[NN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  int n;
  scanf("%d %s", &n, s);
  int lft=0, rgt=0, L=0, R=0;
  for(int i=0; i<n; i++) {
  	if(i<(n/2)) {
  		if(s[i] == '?') L++;
  		else lft+=s[i]-'0';
  	}else {
  		if(s[i] == '?') R++;
  		else rgt+=s[i]-'0';
  	}
  }
  
  if(lft+((L+1)/2)*9>rgt+((R+1)/2)*9) puts("Monocarp");
  else if(lft+((L+1)/2)*9<rgt+((R+1)/2)*9) puts("Monocarp");
  else puts("Bicarp");
  
  return 0;
}