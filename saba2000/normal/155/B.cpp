#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{int k=0,n,t=1,p;
vector <int> v;
cin>>n;
for (int i=0; i<n; i++)
{int a,b; cin>>a>>b;
if (b>0) {k+=a; t+=b-1;} else
v.push_back(a);
}
p=v.size();
sort (v.rbegin(),v.rend());
for (int i=0; i<min(t,p); i++)
k+=v[i];
cout<<k<<endl;
return 0;
}