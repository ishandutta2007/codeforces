#include <iostream>
using namespace std;
int gcd(int a, int b){ if(b==0){ return a; } else{ return gcd(b,a%b); } }
bool g(long long a){ int l=0,r=min(a+1,1001*1LL); while(r-l>1){ int m=(r+l)/2; if(m*m*m>a)r=m; else l=m; } return l*l*l ==a; }

bool good(long long b, long long a){ if(a%b)return 0; a/=b; return g(a); } 

int main(){ cin.tie(0);ios_base::sync_with_stdio(false);int t; cin >> t; while(t-->0){ int a,b; cin>>a>>b; long long g,h; g=gcd(a,b); h=a; h*=b; h/=g*g; if(good(h,g)){ cout<<"Yes\n"; } else{ cout<<"No\n"; } } }