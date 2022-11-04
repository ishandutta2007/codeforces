#include <bits/stdc++.h>
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  int a, b, c, d, n;
  cin>>a>>b>>c>>d>>n;
  int e=a*c+b*d-n, f, g;
  cout<<max(0, a+b-e)<<' ';
  
  if(c>d) swap(a, b), swap(c, d);
  
	f=min(a, n/c);
	n-=f*c;
	
	g=min(b, n/d);
	cout<<f+g<<endl;
  
  return 0;
}