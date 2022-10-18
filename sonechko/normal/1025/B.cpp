#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;

map<int,int> mt;
int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    ll p=0;
    vector<int> v;
    for (int i=1; i<n; i++)
        cin>>a[i]>>b[i];

        ll x,y;
        cin>>x>>y;
        for (int d=2; d*d<=max(x,y); d++)
        {
            if (x%d==0||y%d==0) {v.pb(d); if (mt[d]==n) {cout<<d<<endl; return 0;}}
            while (x%d==0)
                x/=d;
            while (y%d==0)
                y/=d;
        }
        if (x>1) v.pb(x);
        if (y>1&&x!=y) v.pb(y);

    for (int j=0; j<v.size(); j++)
    {
        int t=0;
        for (int p=1; p<n; p++)
            if (a[p]%v[j]!=0&&b[p]%v[j]!=0) t=1;
        if (t==0) {cout<<v[j]; return 0;}
    }
    cout<<-1;
}