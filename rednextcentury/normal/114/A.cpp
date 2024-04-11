
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
    long long k,l;
    cin>>k>>l;
    int im=0;
    long long j=k;
    if (k==l)
    {
        cout<<"YES"<<endl<<0<<endl;
        return 0;
    }
    while(k<l)
    {
        k*=j;
        im++;
        if (k==l)
        {
            cout<<"YES"<<endl;
            cout<<im<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}