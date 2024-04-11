#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ss second
#define ff first
#define ll long long
#define ld long double
#define endl "\n"
#define mp make_pair

const ll N = 3e5 + 11;

int ss[N],pos[N],a[N],t[N],n;

void inc(int l, int d)
{
    for (int i=l; i<=n; i=(i|(i+1)))
        t[i]+=d;
}
int sum(int r)
{
    int res=0;
    for (int i=r; i>=0; i=(i&(i+1))-1)
        res+=t[i];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }
    string s;
    cin>>s;
    s="."+s;
    for (int i=n; i>=1; i--)
    {
        pos[a[i]]+=sum(a[i]);
        inc(a[i],1);
    }
    for (int i=1; i<=n; i++)
        if (s[i]=='1') ss[i]=ss[i-1]+1; else ss[i]=ss[i-1];
    for (int i=1; i<=n; i++)
        if (ss[pos[i]-1]-ss[i-1]!=(pos[i]-i))
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
}