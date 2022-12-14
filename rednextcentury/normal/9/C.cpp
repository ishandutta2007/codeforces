# include <iostream>
# include <stdio.h>
# include <algorithm>
# include <cmath>
using namespace std;
int a[100];
int n;
int ans=0;
void solve(int idx)
{
    long long cur=0;
    for (int i=0;i<idx;i++)
        cur=cur*10+a[i];
    if (cur>n)
        return;
    else
    {
        ans++;
        a[idx]=0;
        solve(idx+1);
        a[idx]=1;
        solve(idx+1);
    }
}
int main()
{
    a[0]=1;
    cin>>n;
    solve(1);
    cout<<ans<<endl;
}