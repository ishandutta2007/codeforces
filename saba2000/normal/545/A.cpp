#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <iomanip>
using namespace std;
int main ()
{int n,a[100][100]={-1};
vector <int> an;
cin>>n;
for (int i=0; i<n; i++)
for (int j=0; j<n; j++)
cin>>a[i][j];
for (int i=0; i<n; i++)
{int s=0;
for (int j=0; j<n; j++)
if (a[i][j]==0 || a[i][j]==2) s++;
if (s==n-1) an.push_back(i+1);
}
cout<<an.size()<<endl;
for (int i=0;i<an.size();i++)
cout<<an[i]<<" ";
cout<<endl;
return 0;
}