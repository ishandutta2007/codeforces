#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll x;
    cin>>x;
    vector<pair<ll,ll> > vec;
    for (ll i=2;i*i<=x;i++) {
        if (x%i==0) {
            int num=0;
            ll c=1;
            while(x%i==0)x/=i,num++,c=c*i;
            vec.push_back({i,c});
        }
    }
    if (x>1)vec.push_back({x,x});
    int n = vec.size();
    ll ret=1e18,bA,bB;
    for (int j=0;j<(1<<n);j++) {
        ll A=1,B=1;
        for (int i=0;i<n;i++) {
            if ((1<<i)&j)A*=vec[i].second;
            else B*=vec[i].second;
        }
        if (max(A,B)<ret){
            ret=max(A,B);
            bA=A,bB=B;
        }
    }
    cout<<bA<<' '<<bB<<endl;
}