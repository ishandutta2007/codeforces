#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

void up()
{
    int n;
    cin>>n;
    vector<int> vs;
    vs.pb(0);
    int d=n;
    while (d>0)
    {
        int l=1,r=d;
        while (r-l>1)
        {
            int mid=(l+r)/2;
            if (n/mid==n/d) r=mid; else l=mid;
        }
        if (n/l==n/d) d=l; else d=r;
        vs.pb(n/d);
        d--;
    }
    cout<<vs.size()<<"\n";
    for (int i=0; i<vs.size(); i++)
        cout<<vs[i]<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}