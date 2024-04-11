#include<bits/stdc++.h>
using namespace std;

map<int,int> mt;

const int N = 1e6 + 11;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        ll x,y;
        cin>>x>>y;
        mt.clear();
        while (x<y)
        {
            if (x%2==1&&x!=1) x--; else
            if (x%2==1) break;
            if (mt[x]==3) break;
            mt[x]++;
            x/=2;
            x*=3;
        }
        if (x<y) cout<<"NO\n"; else cout<<"YES\n";
    }
}