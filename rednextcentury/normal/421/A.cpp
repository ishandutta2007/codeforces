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
int a[100000];
int main()
{
    int n,a1,a2;
    cin>>n>>a1>>a2;
    for (int i=0;i<a1;i++)
    {
        int x;
        cin>>x;
        a[x-1]=1;
    }
    for (int i=0;i<a2;i++)
    {
        int x;
        cin>>x;
        a[x-1]=2;
    }
    for (int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}