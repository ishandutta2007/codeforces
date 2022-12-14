# include <iostream>
# include <stdio.h>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <map>
# include <iomanip>
# include <string>
# include <ios>
# include <queue>
# include <algorithm>
using namespace std;
int main()
{
    int n,m,s,l;
    cin>>n>>m>>s>>l;
    bool p=1;
    bool ss=1;
    bool ll=1;
    for (int i=0;i<m;i++)
    {
        int h;
        cin>>h;
        if (h>l || h<s)
            p=0;
        if (h==l)
            ll=0;
        if (h==s)
            ss=0;
    }
    if (p==0)
    {
        cout<<"Incorrect\n";
        return 0;
    }
    else
    {
        if (n-m>=ss+ll)
            cout<<"Correct\n";
        else
            cout<<"Incorrect\n";
    }
}