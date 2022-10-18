#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int sum[N];
int l1[N],l0[N],r1[N],r0[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    s="."+s;
    sum[0]=0;
    for (int i=1; i<=n; i++)
    {
        if (s[i]=='1') sum[i]=sum[i-1]+1; else sum[i]=sum[i-1];
        l1[i]=l1[i-1];
        l0[i]=l0[i-1];
        if (s[i]=='1') l1[i]=i; else l0[i]=i;
    }
    for (int i=n; i>=1; i--)
    {
        r1[i]=r1[i+1];
        r0[i]=r0[i+1];
        if (s[i]=='1') r1[i]=i; else r0[i]=i;
    }
    for (int i=1; i<=n-k+1; i++)
        if (sum[i+k-1]-sum[i-1]==sum[n]) {cout<<"tokitsukaze"; return 0;} else
        if (k-(sum[i+k-1]-sum[i-1])==n-sum[n]) {cout<<"tokitsukaze"; return 0;}

    int ans=1;
    for (int i=1; i<=n-k+1; i++)
    {
        int l=i;
        int r=i+k-1;
        /// 0
        if (l1[l-1]!=0&&r1[r+1]!=0) ans=0; else
        if (l1[l-1]!=0&&l1[l-1]-r1[1]+1<=k) {} else
        if (r1[r+1]!=0&&l1[n]-r1[r+1]+1<=k) {} else ans=0;
        /// 1
        if (l0[l-1]!=0&&r0[r+1]!=0) ans=0; else
        if (l0[l-1]!=0&&l0[l-1]-r0[1]+1<=k) {} else
        if (r0[r+1]!=0&&l0[n]-r0[r+1]+1<=k) {} else ans=0;
    }
    if (ans==1) cout<<"quailty"; else
        cout<<"once again";
}