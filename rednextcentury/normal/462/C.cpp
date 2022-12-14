#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <set>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;
long long a[1000000];
long long ans=0;
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    if (n==1)
        cout<<a[0]<<endl;
    else
    {
        sort(a,a+n);
        int mult=2;
        for (int i=0;i<n;i++)
        {
            ans+=mult*a[i];
            if (i<n-2)
                mult++;
        }
        cout<<ans<<endl;
    }
}