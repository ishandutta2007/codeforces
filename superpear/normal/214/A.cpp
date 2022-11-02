#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int m,n,ans=0;
    cin>>n>>m;
    for (int i=0;i<=n;i++)
      for (int j=0;j<=m;j++)
        if ((i*i+j==n)&&(j*j+i==m))
          ans++;
    cout<<ans<<endl;
    return 0;
}