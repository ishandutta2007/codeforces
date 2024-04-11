# include <iostream>
# include <string>
# include <map>
# include <stdio.h>
# include <cmath>
# include <cstdio>
# include <queue>
# include <algorithm>
# include <stack>
# include <cstring>
# include <iomanip>
# include<cstdlib>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int buses=1;
    int now=0;
    for (int i=0;i<n;i++)
    {
        int h;
        cin>>h;
        now+=h;
        if (now>m)
        {
            now=h;
            buses++;
        }
    }
    cout<<buses<<endl;
}