#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n,a[1002],max=0,sum=0,now=1;
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for (int i=1;i<n;i++)
    {
        if (a[i]==a[i-1])
          now++;
        else
        {
            sum++;
            if (now>max) max=now;
            now=1;
        }
    }
    if (now>max) max=now;
    sum++;
    cout<<max<<" "<<sum;
    return 0;
}