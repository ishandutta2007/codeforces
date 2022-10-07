#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
int main ()
{
vector <int> v;
int n,l,i=0,a,s,m;
cin>>n>>l;
while (i<n)
{cin>>s;
v.push_back(s);
i++;
}
i=0;
sort(v.begin(),v.end());
a=v[0]*2;

while  (i<v.size()-1)
{
if (v[i+1]-v[i]>a) a=v[i+1]-v[i];
i++;

}
m=v.size();
if ((l-v[m-1])*2>a) a=(l-v[m-1])*2;

 cout<<setiosflags(ios::fixed)<<setprecision(10)<<(double)a/2<<endl;

return 0;
}