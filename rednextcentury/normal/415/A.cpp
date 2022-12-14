# include <iostream>
# include <stdio.h>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <cmath>
# include <iomanip>
# include <queue>
# include <ios>
# include <vector>
# include <algorithm>
using namespace std;
int a[10000];
int main()
{
    memset(a,-1,sizeof(a));
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        for (int i=x-1;i<n;i++)
        {
            if (a[i]==-1)
                a[i]=x;
        }
    }
    for (int i=0;i<n;i++)
        cout<<a[i]<<" ";
cout<<"\n";
}