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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int k=n/2;
    int stand=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='X')
            stand++;

    }
    int sit=n-stand;
    int moves=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='X')
        {
            if (stand>sit)
            {
                s[i]='x';
                sit++;
                moves++;
                stand--;
            }
        }
        if (s[i]=='x')
        {
            if (sit>stand)
            {
                sit--;
                moves++;
                stand++;
                s[i]='X';
            }
        }
        if (sit==stand)
            break;
    }
    cout<<moves<<endl;
    cout<<s<<endl;
}