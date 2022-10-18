#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 2e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int nn=0,zz=0;
    for (int i=1; i<=n; i++)
    {
        char c;
        cin>>c;
        if (c=='z') zz++;
        if (c=='n') nn++;
    }
    for (int i=1; i<=nn; i++)
        cout<<1<<" ";
    for (int i=1; i<=zz; i++)
        cout<<0<<" ";
}
/**
8
1 1 1 1 210 140 84 60
**/