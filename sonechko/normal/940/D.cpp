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
const int N = 1e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    string b;
    cin>>b;
    b="."+b;
    int l=-1000000000,r=1000000000;
    for (int i=5; i<=n; i++)
        if (b[i]=='1'&&b[i-1]=='0'&&b[i-2]=='0'&&b[i-3]=='0'&&b[i-4]=='0')
    {
        l=max(l,a[i]+1);
        l=max(l,a[i-1]+1);
        l=max(l,a[i-2]+1);
        l=max(l,a[i-3]+1);
        l=max(l,a[i-4]+1);
    } else
    if (b[i]=='0'&&b[i-1]=='1'&&b[i-2]=='1'&&b[i-3]=='1'&&b[i-4]=='1')
    {
        r=min(r,a[i]-1);
        r=min(r,a[i-1]-1);
        r=min(r,a[i-2]-1);
        r=min(r,a[i-3]-1);
        r=min(r,a[i-4]-1);
    }
    cout<<l<<" "<<r<<endl;
}