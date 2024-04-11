
# include <iostream>
# include <string>
# include <algorithm>
# include <map>
#include<stdio.h>
# include <vector>
#define EPS 1e-9
using namespace std;
void print(int n)
{
    if (n/10==0)
        cout<<0<<n;
    else
        cout<<n;
}
int main()
{
    int h,m;
    char x;
    cin>>h>>x>>m;
    while(1)
    {
        m++;
        if (m==60)
            m=0,h++;
        if (h==24)
            h=0;
        if (h%10 == m/10 && m%10==h/10)
        {
            print(h);
            cout<<x;
            print(m);
            cout<<endl;
            return 0;
        }
    }
}