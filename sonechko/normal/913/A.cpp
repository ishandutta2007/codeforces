#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ll long long

const int N = 1e6 + 11;

int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int x=1,kol=0;
    while(x*2<=m&&kol<n)
    {
        kol++;
        x*=2;
    }
    if (kol==n) cout<<m%x<<endl; else
        cout<<m<<endl;
}