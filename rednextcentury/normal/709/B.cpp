#include<bits/stdc++.h>
using namespace std;
int x[2000000];
int solve(int l,int r, int s)
{
    if (l>r)return 0;
    int ret=1000000000;
    // l then r
    if (s<=x[l])
        ret=x[r]-s;
    else if (s>=x[r])
        ret=s-x[l];
    else
    {
        ret = min(ret, min(s-x[l],x[r]-s)*2+max(s-x[l],x[r]-s));
    }
    return ret;
}
int main()
{
    int n,s;
    cin>>n>>s;
    for (int i=0;i<n;i++)
        cin>>x[i];
    sort(x,x+n);
    cout<<min(solve(0,n-2,s),solve(1,n-1,s))<<endl;
}