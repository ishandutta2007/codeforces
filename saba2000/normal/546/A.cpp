#include       <iostream>
using namespace std;
int main ()
{int k,n,w;
cin>>k>>n>>w;
if (w*(w+1)/2*k<=n) cout<<0<<endl; else cout<<(w*(w+1)*k/2)-n<<endl;

return 0;
}