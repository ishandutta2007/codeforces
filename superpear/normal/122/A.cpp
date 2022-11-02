#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

int lucky(int s)
{
    for (;s>0;s/=10)
      if ((s%10!=4)&&(s%10!=7))
        return 0;
    return 1;
}

int main()
{
    int n,flag=1;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        if ((n%i==0)&&(lucky(i)))
        {
            flag=0;
            break;
        }
    }
    if (not flag) cout<<"YES"; else cout<<"NO";
    return 0;
}