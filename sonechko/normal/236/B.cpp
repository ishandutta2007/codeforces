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
const int N = 1e6 + 11;

ll kol[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    for (int i=1; i<=a; i++)
    for (int j=1; j<=b; j++)
    for (int d=1; d<=c; d++)
        kol[i*j*d]++;
    ll res=0;
    for (int i=1; i<=1000000; i++)
    if (kol[i]>0)
    {
        ll kk=0;
        for (int j=1; j<=(int)sqrt(i); j++)
        if (i%j==0)
        {
            kk++;
            if (j*j!=i) kk++;
        }
        res=(res+kk*kol[i])%1073741824;
    }
    cout<<res<<endl;
}