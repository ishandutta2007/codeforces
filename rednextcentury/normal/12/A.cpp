# include <iostream>
# include <stdio.h>
# include <algorithm>
# include <map>
using namespace std;
int main()
{
    char a[3][3];
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            cin>>a[i][j];
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            if (a[i][j]!='.' && a[i][j]!=a[2-i][2-j])
            {
                cout<<"NO"<<endl;
                return 0;
            }
    cout<<"YES"<<endl;
}