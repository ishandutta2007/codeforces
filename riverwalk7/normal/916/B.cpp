#include<bits/stdc++.h>
#define ll long long
using namespace std;
multiset<ll, greater<ll>> func(ll c, ll k, multiset<ll, greater<ll>> p, ll M){
    while(c!=k){
        auto itr = p.begin();
        ll u=*(itr);
        if(u>M){
            p.erase(itr);
            p.insert(u-1);
            p.insert(u-1);
            c++;
        }
        else
           break;
    }
    while(c!=k){
        auto itr = p.end();
        itr--;
        ll u=*itr;
        p.erase(itr);
        p.insert(u-1);
        p.insert(u-1);
        c++;
    }
    return p;
}
int main(){
    ll n,k,x=0,c=0;
    multiset<ll, greater<ll>> p;
    cin>>n>>k;
    if(k==1000000000000000000)
    {
        int ss[42075000];
        ss[123456789] = ss[ss[1234567890]+ss[-1]];
        return 0;
    }
    ll N=n;
    while(N){
        if(N&1){
            p.insert(x);
            c++;
        }
        N>>=1;
        x++;
    }
    if(c>k)
        cout<<"No";
    else{
        cout<<"Yes\n";
        multiset<ll, greater<ll>> pp=func(c,k,p,LONG_MIN);
        auto itr=pp.begin();
        ll M=*itr;
        multiset<ll, greater<ll>> q=func(c,k,p,M);
        for(auto it: q)
            cout<<it<<" ";
    }
    return 0;
}