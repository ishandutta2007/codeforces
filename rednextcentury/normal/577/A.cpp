# include <iostream>
#include <cmath>
# include <cstdio>
# include <string>
# include <algorithm>
# include <cstdlib>

using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    long long ans=0;
    for (int i=1;i*i<=x;i++)
    {
        if (x%i!=0) continue;
        int a=x/i;
        int b=i;
        if (a<=n && b<=n)
        {

                    ans++;
        if (a!=b)
            ans++;}
    }
    cout<<ans<<endl;
    return 0;
}