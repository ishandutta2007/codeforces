#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const int N = 2e5 + 11;

int a[N];

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int res=min(1000000-a[1],a[n]-1);
    for (int i=1; i<n; i++)
    {
        res=min(res,max(a[i]-1,1000000-a[i+1]));
    }
    cout<<res<<endl;
}