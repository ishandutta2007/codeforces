#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{int n,m1,m2,i,g;
vector <int> v;
cin>>n;
for (int k=0; k<n; k++)
{cin>>g; v.push_back(g);}
sort(v.rbegin(),v.rend());
for (i=0; i<v.size(); i++)
{m1=0; m2=0;
for (int j=0; j<v.size(); j++)
if (j<=i) m1+=v[j]; else m2+=v[j];
if (m1>m2) break;
}
cout<<i+1<<endl;
//system ("pause");
return 0;
}