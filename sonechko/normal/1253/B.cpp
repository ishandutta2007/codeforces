#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 1e6 + 11;

int d[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
    int n;
    cin>>n;
    vector<int> p;
    int ks=0,last=1;
    vector<int> ds;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        if (l>0)
        {
            if (d[l]==0) {d[l]=1; ks++;} else return cout<<-1, 0;
        } else
        {
            l=-l;
            if (d[l]!=1) return cout<<-1, 0; else
            {d[l]=2; ks--; ds.pb(l);}
            if (ks==0)
            {
                p.pb(i-last+1);
                last=i+1;
                for (int j=0; j<ds.size(); j++)
                    d[ds[j]]=0;
            }
        }
    }
    if (ks>0) return cout<<-1, 0;
    cout<<p.size()<<"\n";
    for (int i=0; i<p.size(); i++)
        cout<<p[i]<<" ";
    cout<<"\n";
}