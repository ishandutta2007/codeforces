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


int a[22222];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  int n;
  scanf("%d", &n);
  int sum=0;
  for(int i=0; i<n; i++) {
  	scanf("%d", a+i);
  	sum+=a[i]/2;
  }
  for(int i=0; i<n; i++) {
  	if(abs(a[i])%2 == 0) printf("%d\n", a[i]/2);
  	else {
  		if(sum<0 && a[i]>0) printf("%d\n", a[i]/2+1), sum++;
  		else if(sum>0 && a[i]<0) printf("%d\n", a[i]/2-1), sum--;
  		else printf("%d\n", a[i]/2);
  	}
  }
  
  return 0;
}