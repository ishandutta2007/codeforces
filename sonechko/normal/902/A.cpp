#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
const int N = 1e6 + 11;

int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i]>>b[i];
    int x=0;
    for (int i=1; i<=n; i++)
        if (x>=a[i]) x=max(x,b[i]);
    if (x>=m) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}