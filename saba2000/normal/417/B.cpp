#include <iostream>
using namespace std;
int main ()
{int n,an=0,w[100009]={0};
cin>>n;
for (int i=0; i<n; i++)
{int x,k;
cin>>x>>k;
if (x>w[k]) an=1;
if (w[k]==x) w[k]++;
}
if (an==0) cout<<"YES"<<endl; else cout<<"NO"<<endl;
return 0;
}