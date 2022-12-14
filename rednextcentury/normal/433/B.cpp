# include <iostream>
# include <string>
# include <map>
# include <stdio.h>
# include <cmath>
# include <cstdio>
# include <queue>
# include <algorithm>
# include <stack>
# include <cstring>
# include <iomanip>
# include<cstdlib>
using namespace std;
long long  a[1000000];
long long  b[1000000];
int  main()
{
    long long  n,m;
    cin>>n;
    for (long long  i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    cin>>m;
    for (long long  i=1;i<n;i++)
    {
        a[i]+=a[i-1];
        b[i]+=b[i-1];
    }
    for (long long  i=0;i<m;i++)
    {
        long long  t,l,r;
        cin>>t>>l>>r;
        if (t==2)
        {
            l--;r--;
            long long  v;
            if (l==0)
                v=0;
            else
                v=b[l-1];
            cout<<b[r]-v<<endl;
        }
        else if (t==1)
        {
            l--;r--;
            long long  v;
            if (l==0)
                v=0;
            else
                v=a[l-1];
            cout<<a[r]-v<<endl;;
        }
    }
}