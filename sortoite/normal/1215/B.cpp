#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int NN = 2e5+10;

int a[NN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  int n;
  scanf("%d", &n);
  for(int i=1; i<=n; i++) {
  	scanf("%d", a+i);
  	a[i]=(a[i]<0);
  }
  
  LL ans=0;
  int pos=0, neg=0;
  for(int i=1; i<=n; i++) {
  	if(a[i]) {
  		swap(pos, neg);
  		neg++;
  	}else {
  		pos++;
  	}
  	ans+=neg;
  }
  cout<<ans<<' '<<(LL)n*(n+1)/2-ans<<endl;
  return 0;
}