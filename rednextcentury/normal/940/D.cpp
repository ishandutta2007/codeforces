#include <bits/stdc++.h>
using namespace std;
string b;
int a[1000000];
bool Ok(int l,int r,char x)
{
    for (int i=l;i<=r;i++)
        if (b[i]!=x)
            return 0;
    return 1;
}
int GetMax(int l,int r)
{
    int mx=a[l];
    for (int i=l+1;i<=r;i++)
        mx=max(mx,a[i]);
    return mx;
}
int GetMin(int l,int r)
{
    int mn=a[l];
    for (int i=l+1;i<=r;i++)
        mn=min(mn,a[i]);
    return mn;
}
int main()
{
    int L1=-1000000000,R1=1000000000;
    int L2=-1000000000,R2=1000000000;
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    cin>>b;
    for (int i=4;i<n;i++)
    {
        if (Ok(i-4,i-1,'0'))
        {
            int mx = GetMax(i-4,i);
            if (b[i]=='0')
            {
                R1 = min(R1,mx);
            }
            else
            {
                L1= max(L1,mx+1);
            }
        }
        else if (Ok(i-4,i-1,'1'))
        {
            int mn = GetMin(i-4,i);
            if (b[i]=='0')
            {
                R2 = min(R2,mn-1);
            }
            else
            {
                L2 = max(L2,mn);
            }
        }
    }
    cout<<L1<<' '<<R2<<endl;
}