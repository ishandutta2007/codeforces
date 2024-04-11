#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int N = 1000 + 11;

int a[N];
int dp[N][2][2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int ans=0;
    for (int i=2; i<=n; i++)
    if (a[i]==1&&a[i-1]==0&&a[i-2]==1) {ans++; a[i]=0;}
    cout<<ans;
}