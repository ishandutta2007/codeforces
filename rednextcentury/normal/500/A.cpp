#include<iostream>
# include <cstring>
#include <algorithm>
#include <stdio.h>
#include<vector>
using namespace std;
int a[100000];
int main()
{
    int n,t;
    cin>>n>>t;
    for (int i=0;i<n-1;i++)
    {
        cin>>a[i];
    }
    int h=0;
    t--;
    while(true)
    {
        if (h>t)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        if (h==t)
        {
            cout<<"YES"<<endl;
            return 0;
        }
        h+=a[h];
    }
}