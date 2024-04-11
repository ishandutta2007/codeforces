#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int a[N];

void up()
{
    int n;
    cin>>n;
    int k1=0,k2=0;
    for (int i=1; i<=n*2; i++)
    {
        int x;
        cin>>x;
        if (x%2==0) k1++; else k2++;
    }
    if (k1==k2) cout<<"Yes\n"; else cout<<"No\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
        up();
}