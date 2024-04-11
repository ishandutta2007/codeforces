
# include <iostream>
# include <string>
# include <algorithm>
# include <map>
#include<stdio.h>
# include <vector>
#define EPS 1e-9
using namespace std;
int a[]={4,7,44,47,74,77,444,447,474,477,744,747,774,777};
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<14;i++)
    {
        if (n%a[i]==0)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}