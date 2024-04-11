#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;
const int P1 = 31;
const int P2 = 47;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;

int d1[N],d2[N];

void up()
{
    string s;
    cin>>s;
    s="."+s;
    int n=s.size()-1;
    int l=1,r=n,k=0;
    while (l<r&&s[l]==s[r])
    {
        k++;
        l++;
        r--;
    }
    for (int i=1; i<=n; i++)
    {
        int l=i,r=i;
        d1[i]=0;
        while (l>=1&&r<=n&&s[l]==s[r])
        {
            d1[i]++;
            l--;
            r++;
        }
        l=i; r=i+1;
        d2[i]=0;
        while (l>=1&&r<=n&&s[l]==s[r])
        {
            d2[i]++;
            l--;
            r++;
        }
    }
    string ans="";
    for (int ks=0; ks<=k; ks++)
    {
        int l=ks+1,r=n-ks;
        for (int j=l; j<=r; j++)
        {
            if (d1[j]<=j-l) continue;
            int t=j-l;
            if (j+t>r) continue;
            if (ks*2+t+t+1>ans.size())
            {
                ans="";
                for (int p=1; p<=ks+t+t+1; p++)
                    ans+=s[p];
                for (int p=n-ks+1; p<=n; p++)
                    ans+=s[p];
            }
        }
        for (int j=l; j<=r; j++)
        {
            if (d2[j]<=j-l) continue;
            int t=j-l;
            if (j+t+1>r) continue;
            if (ks*2+t+t+2>ans.size())
            {
                ans="";
                for (int p=1; p<=ks+t+t+2; p++)
                    ans+=s[p];
                for (int p=n-ks+1; p<=n; p++)
                    ans+=s[p];
            }
        }
        for (int j=l; j<=r; j++)
        {
            if (d1[j]<=r-j) continue;
            int t=r-j;
            if (j-t<l) continue;
            if (ks*2+t+t+1>ans.size())
            {
                ans="";
                for (int p=1; p<=ks; p++)
                    ans+=s[p];
                for (int p=n-(ks+t+t+1)+1; p<=n; p++)
                    ans+=s[p];
            }
        }
        for (int j=l+1; j<=r; j++)
        {
            if (d2[j-1]<=r-j) continue;
            int t=r-j;
            if (j-t-1<l) continue;
            if (ks*2+t+t+2>ans.size())
            {
                ans="";
                for (int p=1; p<=ks; p++)
                    ans+=s[p];
                for (int p=n-(ks+t+t+2)+1; p<=n; p++)
                    ans+=s[p];
            }
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}