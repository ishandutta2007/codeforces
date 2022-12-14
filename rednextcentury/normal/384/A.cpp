# include <iostream>
# include <string>
# include <algorithm>
# include <cmath>
# include <queue>
# include <ios>
# include <map>
using namespace std;
char a[1000][1000];
int main()
{
    int n;
    cin>>n;
    int s=0;
    for (int i=0;i<n;i++)
    {
        for (int x=i%2;x<n;x+=2)
        {
            a[i][x]='C';
            s++;
        }
    }
    cout<<s<<endl;
    for (int i=0;i<n;i++)
    {
        for (int x=0;x<n;x++)
        {
            if (a[i][x]=='C')
                cout<<'C';
            else
                cout<<'.';
        }
        cout<<endl;
    }
}