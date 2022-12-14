
# include <iostream>
# include <string>
# include <algorithm>
# include <map>
#include<stdio.h>
# include <vector>
#define EPS 1e-9
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    int n=a.length();
    for (int i=0;i<n;i++)
    {
        a[i]=tolower(a[i]);
        b[i]=tolower(b[i]);
    }
    if (a<b)
        cout<<-1<<endl;
    else if (b<a)
        cout<<1<<endl;
    else
        cout<<0<<endl;
}