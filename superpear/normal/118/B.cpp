#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    int n,cs,flag;
    cin>>n;
    for (int i=1;i<=2*n+1;i++)
    {
        flag=1;
        for (int j=1;j<=2*n+1;j++)
        {
            cs=n-abs(i-n-1)-abs(j-n-1);
            if ((cs<0) and (flag==0)) break;
            if (j!=1) cout<<" ";
            if (cs<0) cout<<" ";
            else
            {
                cout<<cs;
                flag=0;
            }
        }
        cout<<endl;
    }
    return 0;
}