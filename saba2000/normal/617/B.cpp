#include <iostream>
using namespace std;
main()
{long long p,k,s=0,n=0,ans=1;
cin>>p;
for (int i=0; i<p; i++)
{cin>>k;
if (k==1 && s==1) {ans*=n+1; }
if (k==1) {s=1; n=0;}
if (k==0) n++;
}

if (s==0) cout<<0<<endl; else cout<<ans<<endl;

}