#include <iostream>
#include <vector>
using namespace std;
int main ()
{
    vector <int> v;
    int n,k,l=0,m,o,min;
    cin>>n;
    int i=0;
    while (i<n)
    {
    cin>>k;
    i++;
    v.push_back(k);
}
for (int i=1; i<n-1; i++)
{
    vector <int> vec;
    for (int j=0; j<n; j++)
    if (i!=j)
    vec.push_back(v[j]);
    int max=-1;
    for (int j=1; j<vec.size(); j++)
{
    if (vec[j]-vec[j-1]>max)
    max=vec[j]-vec[j-1];
}
if (max<min)
min=max;
}
cout<<min<<endl;
return 0;
}