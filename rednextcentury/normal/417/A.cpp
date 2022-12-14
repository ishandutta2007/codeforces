# include <iostream>
# include <stdio.h>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <map>
# include <iomanip>
# include <queue>
# include <ios>
# include <vector>
# include <algorithm>
using namespace std;
int main()
{
    int c,d,n,m,k;
    cin>>c>>d>>n>>m>>k;
    int need=n*m;
    need-=k;
    int ans=0;
    while (need>0)
    {
        int x=min(n,need);
        if (x==0)
            break;
        if (c<x*d)
        {
            ans+=c;
            need-=x;
            if (need==0)
                break;
        }
        else
        {
            ans+=x*d;
            need-=x;
        }
    }
    cout<<ans<<endl;
}