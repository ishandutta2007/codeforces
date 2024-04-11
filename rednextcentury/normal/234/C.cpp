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
int a[1000000];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    long long ans=10000000;
    int postot=0,negtot=0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        if (a[i]<0)
            negtot++;
        else if (a[i]>0)
            postot++;
    }
    int posnow=0,negnow=0;
    for (int i=0;i<n-1;i++)
    {
        if (a[i]<0)
            negnow++;
        else if (a[i]>0)
            posnow++;
        long long now=posnow+(negtot-negnow);
        if (now<ans)
            ans=now;
    }
    cout<<ans+n-(postot+negtot)<<endl;
}