#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{int c,d,n,m,k;
cin>>c>>d>>n>>m>>k;
if (k>=n*m) cout<<0<<endl; else
cout<<min(min((n*m-k)*d,((n*m-k+n-1)/n)*c),((n*m-k)/n)*c+((n*m-k)%n)*d)<<endl;
return 0;
}