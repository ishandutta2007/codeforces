#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int n,a,b,ans=0;
    cin>>n>>a>>b;
    for (int i=1;i<=n;i++)
      if ((i>a)&&((n-i)<=b)) ans++;
    cout<<ans;
    return 0;
}