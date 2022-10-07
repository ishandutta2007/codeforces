#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main ()
{string k;
int s=0;
int a[200000];
cin>>k;
int m,l;
cin>>m;
for (int i=0; i<m; i++)
{cin>>l;
a[l-1]++;
}
for (int i=0; i<k.length()/2; i++)
{s+=a[i];
if (s%2==1) swap(k[i],k[k.length()-i-1]);
}
cout<<k<<endl;
//system ("pause");
return 0;
}