#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 1e6 + 11;

map<string,int> mt;

int getmin(string s)
{
    int n=s.size();
    s="."+s;
    for (int len=1; len<=n; len++)
    {
        mt.clear();
        int kol=0;
        for (int j=1; j<=n-len+1; j++)
        {
            string p="";
            for (int d=j; d<=j+len-1; d++)
                p+=s[d];
            if (mt[p]==0) {kol++; mt[p]=1;} else
            if (mt[p]==1) {kol--; mt[p]=2;}
        }
        if (kol>0) return len;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    if (k==1)
    {
        string ans="1";
        for (int i=1; i<n; i++)
            ans+="0";
        cout<<ans<<endl;
        return 0;
    }
    if (k==n)
    {
        string ans="";
        for (int i=1; i<=n; i++)
            ans+="0";
        cout<<ans<<endl;
        return 0;
    }
    if (k==2)
    {
        string ans="11";
        for (int i=1; i<=n-2; i++)
            ans+="0";
        cout<<ans<<endl;
        return 0;
    }
    if (n%2==0&&k==n-2)
    {
        string ans="";
        for (int i=1; i<=n; i++)
            if (i%2==0) ans+="1"; else ans+="0";
        cout<<ans<<endl;
        return 0;
    }
    if (n%2==0&&(k-2)+k+(k-2)<=n)
    {
        string ans="";
        for (int j=1; j<=(n-k)/2; j++)
            ans+="0";
        ans+="1";
        for (int j=1; j<=k-2; j++)
            ans+="0";
        ans+="1";
        for (int j=1; j<=(n-k)/2; j++)
            ans+="0";
        cout<<ans<<endl;
        return 0;
    }
    if (n%2==0)
    {
        int t=(n-k)/2+1;
        string ans="";
        for (int j=1; j<=n; j++)
            if ((j-1)%t==0) ans+="1"; else ans+="0";
        cout<<ans<<endl;
        return 0;
    }
    if (n%2==1)
    {
        string ans="";
        int t=(n-k)/2+1;
        for (int i=1; i<=n; i++)
            if ((i-1)%t==0) ans+="1"; else ans+="0";
        cout<<ans<<endl;
        ///cout<<getmin(ans)<<" = "<<k<<endl;
        return 0;
    }

    while (1==1)
    {

    }

    cout<<"??? "<<endl;

    for (int p=0; p<(1<<n); p++)
    {
        string c="";
        for (int j=0; j<n; j++)
            if (p&(1<<j)) c+="0"; else c+="1";
        if (getmin(c)==k) {cout<<c<<endl;}
    }

}
/**

5 3

10101

7 3

1001001

7 5
9 3
9 5
9 7

**/