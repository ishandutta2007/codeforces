
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
    int n;
    cin>>n;
    if (n-10>11 || n-10<=0)
        cout<<0<<endl;
    else if (n-10==10)
        cout<<15<<endl;
    else
        cout<<4<<endl;
}