# include <iostream>
# include <algorithm>
# include <set>
# include <stdio.h>
using namespace std;
bool x[1000001];
bool y[1000001];
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int xs,ys;
        cin>>xs>>ys;
        x[xs]=1;
        y[ys]=1;
    }
    int ans=0;
    if (n%2 && (!x[n/2 + 1] || !y[n/2 + 1]))
        ans=1;
    for (int i=2;i<=n/2;i++)
    {
        ans+= (!x[i]) + (!x[n+1-i]) + (!y[i]) + (!y[n+1-i]);
    }
    cout<<ans<<endl;
}