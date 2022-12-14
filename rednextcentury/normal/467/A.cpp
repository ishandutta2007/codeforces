#include <cmath>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ans=0;
    for (int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        if (b-a>1)
            ans++;
    }
    cout<<ans<<endl;
}