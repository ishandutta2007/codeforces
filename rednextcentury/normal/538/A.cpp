# include <iostream>
# include <vector>
# include <stdio.h>
#include <limits.h>
#include <stack>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    for (int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if (s.substr(0,i)+s.substr(j+1,n-j-1)=="CODEFORCES")
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    if (s!="CODEFORCES")
    cout<<"NO"<<endl;
    else
    cout<<"YES"<<endl;
}