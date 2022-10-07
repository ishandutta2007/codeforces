#include <iostream>
#include <vector>
using namespace std;
int main ()
{
    vector <int> a,b;
    int n;
    int s=0,q=0,w=0,e=0,m=0;
    cin>>n;
    int i=1; 
    while (i<=n)
    {
    cin>>s;
    a.push_back(s);
    i++;
}
i=0;
while (1==1)
{
while (i<a.size())
{if (a[i]==1 && q==0)
{q=i+1; a[i]=0;}
if (a[i]==2 && e==0)
{e=i+1; a[i]=0;}
if (a[i]==3 && w==0)
{w=i+1; a[i]=0;}
i++;}
if (q!=0 && e!=0 && w!=0)
{b.push_back(q); b.push_back(e); b.push_back(w); m++;}
else break;
e=0; w=0; q=0;
i=0;
}
i=0;
cout<<m<<endl;
while (i<b.size())
{cout<<b[i]<<" ";
if ((i+1)%3==0) cout<<endl;
i++;
}

return 0;
}