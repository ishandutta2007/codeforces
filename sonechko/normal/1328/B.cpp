#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ld long double

const int N = 1e5 + 11;

void up(int p1, int p2, int n)
{
    for (int i=1; i<p1; i++)
        cout<<'a';
    cout<<'b';
    for (int i=p1+1; i<p2; i++)
        cout<<'a';
    cout<<'b';
    for (int i=p2+1; i<=n; i++)
        cout<<'a';
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        for (int p=n-1; p>=1; p--)
        {
            int kol=n-p;
            if (kol>=k)
            {
                up(p,n-k+1,n);
                break;
            } else k-=kol;
        }
    }
}