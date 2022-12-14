# include <iostream>
# include <stdio.h>
# include <algorithm>
# include <cmath>
using namespace std;
long double xs[100000];
int main()
{
    int n;
    long double vs,vb;
    cin>>n>>vb>>vs;
    for (int i=0;i<n;i++)
        cin>>xs[i];
    int x,y;
    cin>>x>>y;
    int idx=n-1;
    long double mn=xs[n-1]/vb + sqrt((xs[n-1]-x)*(xs[n-1]-x)+y*y)/vs;
    for (int i=n-2;i>=1;i--)
    {
        long double cost=xs[i]/vb + sqrt((xs[i]-x)*(xs[i]-x)+y*y)/vs;
        if (cost<mn)
        {
            mn=cost;
            idx=i;
        }
    }
    cout<<idx+1<<endl;
}