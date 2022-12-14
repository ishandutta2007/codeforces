//#include <cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
#include <map>
#include<cstdio>
using namespace std;
long long b[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>b[i];
    long long ans=0;
    long long added=0;
    for (int i=0;i<n;i++)
    {
        if (b[i]>added)
        {
            ans+=b[i]-added;
            added=b[i];
        }
        else if (b[i]<added)
        {
            ans+=added-b[i];
            added=b[i];
        }
    }
    cout<<ans<<endl;
}