#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{int n,r;
vector <int> v;
cin>>n;
for (int i=0; i<n; i++)
{cin>>r; v.push_back (r);}
sort(v.begin(),v.end());
for (int i=0; i<n; i++)
cout<<v[i]<<" ";
cout<<endl;
//system ("pause");
return 0;
}