# include <iostream>
# include <vector>
# include <cstring>
#include <ios>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (int i=1;i<=n;i++)
    {
        for (int x=0;x<n;x++)
        {
            if (s[x]=='.')
                continue;
            int j=x;
            int num=1;
            while(j<n)
            {
                j+=i;
                if (j<n && s[j]=='*')
                    num++;
                else
                    break;
            }
            if (num>=5)
            {
                cout<<"yes"<<endl;
                return 0;
            }

        }

    }
    cout<<"no"<<endl;
}