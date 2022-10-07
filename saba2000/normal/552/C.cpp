
#include <iostream>
using namespace std;
int F(long long int N,long long int W,long long int M,long long int K)
{if (N==M) return 1; else
if (K>M && W==4) if (N+K*W==M || N-K*W==M ) return 1; else return 0; 
else if (K/W>M) return 0;
else return max(max(F(N+K*W,W,M,K*W),F(N-K*W,W,M,K*W)),F(N,W,M,K*W));
}
int main ()
{long long int m,w;
cin>>w>>m;
if (w==2 || w==3) cout<<"YES"<<endl;
else
if (w>1000000) if ( m==1 ||( m==w || m==w+1 || m==w-1)) cout<<"YES"<<endl; else cout<<"NO"<<endl; 
else
if (F(1,w,m,1)==1 || F(-1,w,m,1)==1 || F(0,w,m,1)==1) cout<<"YES"<<endl;
else cout<<"NO"<<endl;
return 0;
}