#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long n,d,x,y;
        cin>>n>>x>>y>>d;
        long long ret=1e16;
        if (abs(x-y)%d==0)
            ret=min(ret,abs(x-y)/d);
        if ((y-1)%d==0)
            ret=min(ret,(y-1)/d+(x-1)/d+((x-1)%d>0));
        if ((n-y)%d==0)
        {
            ret=min(ret,(n-y)/d+(n-x)/d+((n-x)%d>0));
        }
        if (ret>1e15)
            cout<<-1<<endl;
        else
            cout<<ret<<endl;
    }
}