#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int n,x=0,y=0,z=0,x1,y1,z1;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x1>>y1>>z1;
        x+=x1;y+=y1;z+=z1;
    }
    if ((x==0)&&(y==0)&&(z==0))
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
    return 0;
}