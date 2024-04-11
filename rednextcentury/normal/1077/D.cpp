#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define F first
#define pb push_back
#define S second
#define er erase
#define fi find
#define in insert
#define pi pair<int,int>
#define pii pair<int,pi>
#define go ios::sync_with_stdio(0)
int n,k,a[200100],f[200100],m,mx,sz;
vector <pi> v;
vector<int> ans;
bool com(pi A, pi B)
{
    return A.F>B.F;
}
bool ok(int x)
{
    int sum=0;
    for(int i=0;i<sz;i++)
    {
        sum+=v[i].F/x;
        if(sum>=k)
            return 1;
    }
    return sum>=k;
}
int main()
{
    go;
    cin>>n>>k;
    m=n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        f[a[i]]++;
    }
    for(int i=1; i<=200000; i++)
    {
        if(f[i])
        {
            pi p;
            p.F=f[i];
            p.S=i;
            v.pb({p.F,p.S});
            sz++;
        }
    }
    sort(v.begin(),v.end(),com);
    int st=1,en=1e9;
    while(st<=en)
    {
        int mid=(st+en)/2;
        if(ok(mid))
        {
            mx=mid;
            st=mid+1;
        }
        else
            en=mid-1;
    }
    for(int i=0;i<sz;i++)
    {
        for(int j=0;j<v[i].F/mx;j++)
        {
            cout<<v[i].S<<" ";
            k--;
            if(k==0)
                return 0;
        }
    }
    return 0;
}