#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,res,now;
int main()
{
    cin>>t;
    while(t--)
    {
    cin>>n;res=0;
    for(ll bit=0 ; bit<9 ; bit++)
    {
        vector<ll> a,b;
        for(ll i=1 ; i<=n ; i++)
        {
            if((i&(1<<bit))!=0)
                a.push_back(i);
            else
                b.push_back(i);
        }
        if(!a.size() || !b.size())
            continue;
        cout<<a.size()<<" "<<b.size();
        for(ll k=0 ; k<a.size() ; k++)
            cout<<" "<<a[k];
        for(ll k=0 ; k<b.size() ; k++)
            cout<<" "<<b[k];
        cout<<endl; cout.flush();
        cin>>now;
        res=max(res,now);
    }
    cout<<-1<<" "<<res<<endl; cout.flush();
    }
    return 0;
}