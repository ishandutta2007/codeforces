
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
    string s;
    cin>>s;
    int n=s.length();
    int ret=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='4' || s[i]=='7')
            ret++;
    }
    if (ret==4 || ret==7)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}