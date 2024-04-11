# include <iostream>
# include <stdio.h>
# include <algorithm>
# include <map>
using namespace std;
int main()
{
    int x,y;
    cin>>x>>y;
    int nom=6-max(x,y)+1;
    int denom=6;
    for (int i=nom;i>=2;i--)
    {
        if (nom%i==0 && denom%i==0)
            nom/=i,denom/=i;
    }
    cout<<nom<<"/"<<denom<<endl;
}