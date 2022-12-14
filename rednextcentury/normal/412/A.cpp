# include <iostream>
# include <stdio.h>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <map>
# include <iomanip>
# include <string>
# include <ios>
# include <vector>
# include <algorithm>
using namespace std;
int main()
{
    int n,k;
    string s;
    cin>>n>>k>>s;
    if (k>n/2)
    {
        for (int i=k;i<n;i++)
        {
            cout<<"RIGHT\n";
        }
        for (int i=n-1;i>=0;i--)
        {
            cout<<"PRINT "<<s[i]<<endl;
            if (i>0)
                cout<<"LEFT"<<endl;
        }
    }
    else
    {
        for (int i=k-1;i>0;i--)
            cout<<"LEFT\n";
        for (int i=0;i<n;i++)
        {
            cout<<"PRINT "<<s[i]<<endl;
            if (i<n-1)
                cout<<"RIGHT"<<endl;
        }
    }
}