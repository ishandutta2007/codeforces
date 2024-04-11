#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define ss second
#define ff first
const int MOD = 1000000007;
#define mod %MOD
#define pb push_back
#define ld long double
const int N = 1e6 + 11;
const int MAX = 1e8;

int a[N],b1[N],b2[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    if (k==1)
    {
        int r=1e9;
        for (int i=1; i<=n; i++)
        {
            int l;
            cin>>l;
            r=min(r,l);
        }
        cout<<r<<endl;
        return 0;
    }
    if (k==2)
    {
    int r=-1e9;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        if (i==1||i==n) r=max(r,l);
    }
    cout<<r<<endl;
    return 0;
    }
    int r=-1e9;
    for (int i=1; i<=n; i++)
        {
            int l;
            cin>>l;
            r=max(r,l);
        }
        cout<<r<<endl;
        return 0;
}