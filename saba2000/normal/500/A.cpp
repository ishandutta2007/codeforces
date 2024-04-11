#include <iostream>
#include <vector>
using namespace std;
int main ()
{int n,t,r,i;
vector <int> v;
cin>>n>>t;
for (i=1; i<n; i++)
{cin>>r;
v.push_back(r);
}
for (i=1; i<t; i+=0)
{ i+=v[i-1];}
if (i==t) cout<<"YES"<<endl; else cout<<"NO"<<endl;
//system ("pause");
return 0;
}