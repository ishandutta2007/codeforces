#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    cin>>a[i];
    for (int d=0; d<(1<<n); d++)
    {
        int k=0;
        for (int j=1; j<=n; j++)
            if (d&(1<<(j-1))) k=(k+a[j])%360; else
            k=(k+360-a[j])%360;
        if (k==0)
        {
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
}