#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{long long int c[100009],n,x,an=0;
cin>>n>>x;
for (int i=0; i<n; i++)
cin>>c[i];
sort (c,c+n);
for (int i=0; i<n; i++)
{an+=c[i]*x;
if(x>1)x--;
}
cout<<an<<endl;
return 0;
}