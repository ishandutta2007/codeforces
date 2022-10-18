#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
const int N = 2e5 + 11;

int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=m; i++)
        cin>>b[i];
    int pos=0,sum=0,ss=0;
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        sum+=a[i];
        while (ss+b[pos+1]<=sum&&pos<m)
        {
            pos++;
            ss+=b[pos];
        }
        if (ss==sum) {ans++;}
    }
    cout<<ans<<endl;
}