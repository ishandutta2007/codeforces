#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define ull unsigned long long

const int N = 2e6 + 11;

map<ll,int> mt;

ll a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
    {
        mt.clear();
        for (int j=1; j<=n; j++)
            mt[a[j]]++;
        vector<ll> vv;
        vv.pb(a[i]);
        mt[a[i]]--;
        while (1==1)
        {
            ll p=vv.back();
            if (mt[p*2]&&p%3==0&&mt[p/3]) break;
            if (mt[p*2]) {mt[p*2]--; vv.pb(p*2);} else
            if (mt[p/3]&&p%3==0) {mt[p/3]--; vv.pb(p/3);} else
                break;
        }
        if (vv.size()==n)
        {
            for (int j=0; j<vv.size(); j++)
                cout<<vv[j]<<" ";
            cout<<endl;
            return 0;
        }
    }
}