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

const int NN = 1e6+10;

int a[NN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  int n;
  long long k, mx=0, mn=0;
  cin>>n>>k;
  
  mn=(long long)n*(n+1)/2;
  for(int i=1; i<=n; i++) mx+=max(i, n-i+1);
  
  if(k<mn) {
  	puts("-1");
  	return 0;
  }
  smin(k, mx);
  
  cout<<k<<endl;
  k-=mn;
  
  for(int i=1; i<=n; i++) a[i]=i;
  int md=(1+n)/2;
  
  for(int i=1; i<=n && k>0; i++) {
  	int j=n-i+1;
  	if(k>=j-i) {
  		swap(a[i], a[j]);
  		k-=j-i;
  	}else {
  		for(int r=i; ; r++) {
  			if(k == j-r) {
  				swap(a[j], a[r]);
  				k=0;
  				break;
  			}
  		}
  		break;
  	}
  }
  
  for(int i=1; i<=n; i++) printf("%d ", i);puts("");
  for(int i=1; i<=n; i++) printf("%d ", a[i]);puts("");
  
  return 0;
}