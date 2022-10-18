#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
    int n;
    cin>>n;
    int kol=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        kol+=a[i];
    }
    int d=0;
    for (int i=1; i<=n; i++)
    {
        d+=a[i];
        if (d>=(kol+1)/2) {cout<<i<<endl; return 0;}
    }
}