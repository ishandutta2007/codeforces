#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;

int mx[N],dp[N];
string s;
int a[N];

bool good(int x, int y)
{
    string s1="";
    string s2="";
    for (int i=1; i<=x; i++)
        s1+=s[i];
    for (int i=x+1; i<=y; i++)
        s2+=s[i];
    string t=s2+"#"+s1;
    for (int i=1; i<t.size(); i++)
    {
        int j=a[i-1];
        while (j>0&&t[i]!=t[j])
            j=a[j-1];
        if (t[i]==t[j]) j++;
        a[i]=j;
        if (a[i]==(int)s2.size()) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,x,y;
    cin>>n>>x>>y;
    cin>>s;
    s="."+s;
    for (int i=1; i<=n; i++)
    {
        mx[i]=i;
        int pos=0;
        int l=i+1,r=n;
        while (r-l>1)
        {
            int mid=(l+r)/2;
            if (good(i,mid)) l=mid; else r=mid;
        }
        if (good(i,r)) mx[i]=r; else
        if (good(i,l)) mx[i]=l; else mx[i]=i;
    }
    dp[0]=0;
    for (int i=1; i<=n; i++)
    {
        dp[i]=dp[i-1]+x;
        for (int j=i; j>=1; j--)
            if (mx[j-1]>=i) dp[i]=min(dp[i],dp[j-1]+y);
    }
    cout<<dp[n]<<endl;
}