#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ss second
#define ff first
#define ll long long

const int N = 1e6 + 11;

map<ll,ll> mt;
set<ll> st[N];
set<ll> ss;
ll kk[N];
int kol;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        ll l;
        cin>>l;
        if (mt[l]==0)
        {
            kol++;
            mt[l]=kol;
            st[kol].insert(i);
            kk[kol]=l;
        } else
        {
            ll d=mt[l];
            if (st[d].size()==1) ss.insert(l);
            st[d].insert(i);
        }
    }
    while (ss.size()>0)
    {
        ll p=*ss.begin();
        ll d=mt[p];
        ll t1=*st[d].begin();
        st[d].erase(t1);
        ll t2=*st[d].begin();
        st[d].erase(t2);
        if (st[d].size()<=1) ss.erase(p);
        ll dd=mt[p*2];
        if (dd==0)
        {
            kol++;
            mt[p*2]=kol;
            kk[kol]=p*2;
            st[kol].insert(t2);
            if (st[kol].size()==2) ss.insert(p*2);
        } else
        {
            st[dd].insert(t2);
            if (st[dd].size()==2) ss.insert(p*2);
        }
    }
    set<pair<ll,ll> > pp;
    for (int i=1; i<=kol; i++)
    {
        while (st[i].size()>0)
        {
            ll p=*st[i].begin();
            pp.insert(mp(p,kk[i]));
            st[i].erase(p);
        }
    }
    cout<<pp.size()<<endl;
    while (pp.size()>0)
    {
        pair<ll,ll> p=*pp.begin();
        pp.erase(p);
        cout<<p.ss<<" ";
    }
    cout<<endl;
}