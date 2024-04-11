#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define ll long long
#define ld long double
const int N = 2e5 + 11;

int c[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>c[i];
    sort(c+1,c+n+1);
    int pos=1;
    int ans=n;
    for (int i=1; i<=n; i++)
    {
        while (pos<n&&c[pos+1]<=c[i]*2)
            pos++;
        ans=min(ans,i-1+n-pos);
    }
    cout<<ans<<endl;
}