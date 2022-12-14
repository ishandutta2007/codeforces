#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int w,m;
bool ret;
int tot;
void solve(int i,long long s)
{
    if (i==tot)
        ret|=(s==m);
    else
    {
        solve(i+1,s);
        solve(i+1,s+a[i]);
        solve(i+1,s-a[i]);
    }
}
int main()
{
    cin>>w>>m;
    if (w<=3)cout<<"YES"<<endl;
    else
    {
        long long x=1;
        while(x<=m)
        {
            a[tot++]=x;
            x=x*w;
        }
        a[tot++]=x;
        solve(0,0);
        if (ret)cout<<"YES"<<endl;
        else cout<<"NO\n";
    }
}