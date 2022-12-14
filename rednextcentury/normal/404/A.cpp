# include <iostream>
# include <string>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <cmath>
# include <iomanip>
# include <queue>
# include <ios>
# include <vector>
# include <map>
using namespace std;
char a[500][500];
map<char,int> k;
int main()
{
    int n;
    cin>>n;
    int m=0;
    for (int i=0;i<n;i++)
    {
        for (int x=0;x<n;x++)
        {
            cin>>a[i][x];
            if (++k[a[i][x]]==1)
                m++;
        }
    }
    if (m!=2)
        cout<<"NO"<<endl;
    else
    {
        char d=a[0][0];
        char nop=a[0][1];
        bool p=0;
        for (int i=0;i<n;i++)
        {
            for (int x=0;x<n;x++)
            {
                if (i==x)
                {
                    if (a[i][x]!=d)
                        p=1;
                }
                else if (i==n-x-1)
                {
                    if (a[i][x]!=d)
                        p=1;
                }
                else
                    if (a[i][x]!=nop)
                        p=1;
            }
        }
        if (p==1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
}