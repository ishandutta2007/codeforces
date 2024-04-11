# include <iostream>
# include <stdio.h>
# include <map>
# include <string>
# include <queue>
# include <cstdio>
# include <cstdlib>
# include <stack>
# include <cmath>
# include <iomanip>
# include <algorithm>
# include <set>
# include <vector>
using namespace std;
int a[1000000];
int main()
{
    int n,m;
    cin>>n>>m;
    int neg=0;
    int pos=0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        if (a[i]>0)
        pos++;
        else
        neg++;
    }
    for (int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        if ((r-l+1)%2==0 && neg>=(r-l+1)/2 && pos>=(r-l+1)/2)
        cout<<1<<endl;
        else
        cout<<0<<endl;
    }
}