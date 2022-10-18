#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

int dp[N],ss[N],a[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k,d;
    cin>>n>>k>>d;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    dp[0]=1;
    ss[0]=1;
    int pl=1;
    for (int i=1; i<=n; i++)
    {
        while (a[i]-a[pl]>d)
            pl++;
        int l=pl-1;
        int r=i-k;
        if (l==0&&l<=r) dp[i]=1; else
        if (l<=r&&ss[r]-ss[l-1]>0) dp[i]=1;
        ss[i]=ss[i-1]+dp[i];
    }
    if (dp[n]) cout<<"YES\n"; else cout<<"NO\n";
}