#include <iostream>
using namespace std;
int main ()
{ 
long long int n,k,a=1;
cin>>n>>k;
if (k*2<=n+1) cout<<k*2-1<<endl;
else if (n%2==1) cout<<(k-n/2-1)*2;
else cout<<(k-n/2)*2;
return 0;   
}