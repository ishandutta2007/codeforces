#include<bits/stdc++.h>
using namespace std;
string s;
int n,k;
bool check(int m)
{
    int A=0,B=0;
    for (int i=0;i<n;i++)
    {
        if (i<=m-1)
        {
            if (s[i]=='a')
                A++;
            else B++;
            if (i==m-1)
                if (A<=k || B<=k)
                    return 1;
            continue;
        }
        if (s[i]=='a')
                A++;
            else B++;
        if (s[i-m]=='a')
            A--;
        else B--;
        if (A<=k || B<=k)
            return 1;

    }
    return 0;
}
int bs(int l,int r)
{
    int ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if (check(mid))
            ans=mid,l=mid+1;
        else
            r=mid-1;
    }
    return ans;
}
int main()
{
    cin>>n>>k;
    cin>>s;
    cout<<bs(1,n)<<endl;
}